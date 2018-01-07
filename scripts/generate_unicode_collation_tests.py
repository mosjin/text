#!/usr/bin/env python
# -*- coding: utf-8 -*-

from generate_unicode_normalization_data import cccs
from generate_unicode_normalization_data import expand_decomp_canonical
from generate_unicode_normalization_data import get_decompositions
from generate_unicode_collation_data import get_frac_uca_cet
from generate_unicode_collation_data import ce_to_cpp

import re

perf_test_form = decls = '''\
// Warning! This file is autogenerated.
#include <boost/text/collate.hpp>

#include <benchmark/benchmark.h>

{0}

BENCHMARK_MAIN()
'''

verbatim_collation_tests_form = '''\
// Warning! This file is autogenerated.
#include "collation_tests.hpp"

#include <boost/algorithm/cxx14/equal.hpp>

#include <gtest/gtest.h>


{0}
'''

relative_collation_tests_form = '''\
// Warning! This file is autogenerated.
#include "collation_tests.hpp"

#include <algorithm>

#include <gtest/gtest.h>


std::array<uint32_t, {1}> const g_cps = {{{{
{0}
}}}};

std::array<std::pair<uint32_t, uint32_t>, {3}> const g_cp_ranges = {{{{
{2}
}}}};

TEST(collation, relative_{4}_{5})
{{
    std::vector<uint32_t> prev_un_norm;
    std::vector<uint32_t> prev_cps;
    boost::text::text_sort_key prev_key;
    std::vector<uint32_t> curr_un_norm;
    std::vector<uint32_t> curr_cps;
    boost::text::text_sort_key curr_key;

    bool first = true;

    std::pair<uint32_t, uint32_t> prev_r;

    for (auto r : g_cp_ranges) {{
        curr_un_norm.assign(
            g_cps.begin() + r.first, g_cps.begin() + r.second);

        curr_cps.clear();
        boost::text::pseudonormalize_to_fcc(
            curr_un_norm, std::back_inserter(curr_cps));

        curr_key = boost::text::collation_sort_key(
            curr_cps,
            boost::text::collation_strength::identical,
            boost::text::variable_weighting::{4});

        if (!first) {{
            EXPECT_LE(compare(prev_key, curr_key), 0)
                << "prev un-norm cps: " << ce_dumper(prev_un_norm)
                << "prev_cps (FCC):   " << ce_dumper(prev_cps)
                << "prev_key:         " << ce_dumper(prev_key) << "\\n"
                << "curr un-norm cps: " << ce_dumper(curr_un_norm)
                << "curr_cps (FCC):   " << ce_dumper(curr_cps)
                << "curr_key:         " << ce_dumper(curr_key) << "\\n"
            ;
        }}

        std::swap(curr_un_norm, prev_un_norm);
        std::swap(curr_cps, prev_cps);
        std::swap(curr_key, prev_key);

        first = false;

        prev_r = r;
    }}
}}
'''

def indices_to_list(indices, all_cps):
    return all_cps[indices[0]:indices[1]]

def generate_lookup_perf_test(ducet):
    chunk_size = 50
    chunks_per_file = 100

    chunk_arrays = []

    chunk = 0
    i = 0
    cps = []
    cp_ranges = []
    for k,v in sorted(ducet.items()):
        cp_ranges.append((len(cps), len(cps) + len(k)))
        cps += list(k)
        i += 1
        if i == chunk_size:
            chunk_arrays.append((cps, cp_ranges))
            chunk += 1
            i = 0
            cps = []
            cp_ranges = []

    chunk_idx = 0
    lines = ''
    for i in range(len(chunk_arrays)):
        if i != 0 and i % chunks_per_file == 0:
            cpp_file = open('collation_element_lookup_perf_{0:03}.cpp'.format(chunk_idx), 'w')
            cpp_file.write(perf_test_form.format(lines))
            chunk_idx += 1
            lines = ''
        cps = chunk_arrays[i][0]
        cp_ranges = chunk_arrays[i][1]
        lines += '''\
uint32_t cps_{0:03}[] = {{
{1}
}};

void BM_collation_element_lookup_{0:03}(benchmark::State & state)
{{
    while (state.KeepRunning()) {{
'''.format(i, ', '.join(map(lambda x: type(x) == str and '0x' + x or hex(x), cps)), len(cps))
        for first,last in cp_ranges:
            lines += '''\
            benchmark::DoNotOptimize(boost::text::detail::longest_collation(cps_{0:03} + {1}, cps_{0:03} + {2}));
'''.format(i, first, last)
        lines += '''\
    }}
}}
BENCHMARK(BM_collation_element_lookup_{0:03});

'''.format(i)

    cpp_file = open('collation_element_lookup_perf_{0:03}.cpp'.format(chunk_idx), 'w')
    cpp_file.write(perf_test_form.format(lines))

def generate_collation_perf_test(ducet):
    chunk_size = 100
    chunks_per_file = 100

    chunk_arrays = []

    chunk = 0
    i = 0
    cps = []
    cp_ranges = []
    for k,v in sorted(ducet.items()):
        cp_ranges.append((len(cps), len(cps) + len(k)))
        cps += list(k)
        i += 1
        if i == chunk_size:
            chunk_arrays.append((cps, cp_ranges))
            chunk += 1
            i = 0
            cps = []
            cp_ranges = []

    chunk_idx = 0
    lines = ''
    for i in range(len(chunk_arrays)):
        if i != 0 and i % chunks_per_file == 0:
            cpp_file = open('collation_perf_{0:03}.cpp'.format(chunk_idx), 'w')
            cpp_file.write(perf_test_form.format(lines))
            chunk_idx += 1
            lines = ''
        cps = chunk_arrays[i][0]
        cp_ranges = chunk_arrays[i][1]
        lines += '''\
uint32_t cps_{0:03}[] = {{
{1}
}};

void BM_collation_{0:03}(benchmark::State & state)
{{
    while (state.KeepRunning()) {{
'''.format(i, ', '.join(map(lambda x: type(x) == str and '0x' + x or hex(x), cps)), len(cps))
        lines += '''\
        benchmark::DoNotOptimize(boost::text::collation_sort_key(cps_{0:03}, cps_{0:03} + {2}, boost::text::collation_strength::quaternary, boost::text::variable_weighting::shifted));
'''.format(i, cp_ranges[0][0], cp_ranges[-1][1])
        lines += '''\
    }}
}}
BENCHMARK(BM_collation_{0:03});

'''.format(i)

    cpp_file = open('collation_perf_{0:03}.cpp'.format(chunk_idx), 'w')
    cpp_file.write(perf_test_form.format(lines))

collation_elements_regex = re.compile(r'\[([ |0123456789ABCDEF]+)\]')

def generate_verbatim_collation_tests(non_ignorable_filename, shifted_filename):
    non_ignorable_lines = open(non_ignorable_filename, 'r').readlines()

    shifted = {}

    shifted_lines = open(shifted_filename, 'r').readlines()
    for line in shifted_lines:
        line = line[:-1]
        if not line.startswith('#') and len(line) != 0:
            comment_start = line.find('#')
            shifted_comment = ''
            if comment_start != -1:
                shifted_comment = line[comment_start + 1:].strip()
                line = line[:comment_start]
            cps = map(lambda x: '0x' + x, line.split(';')[0].split(' '))
            ces_match = collation_elements_regex.search(shifted_comment)
            ces = ces_match.group(1).replace('|', '0000').split(' ')
            ces = ces[:-1]
            ces_shifted = map(lambda x: '0x' + x, ces)
            shifted[tuple(cps)] = (shifted_comment, ces_shifted)

    contents = ''
    chunk_idx = 0
    line_idx = 0 
    for i in range(len(non_ignorable_lines)):
        non_ignorable_line = non_ignorable_lines[i]
        if line_idx == 500:
            cpp_file = open('verbatim_collation_test_{0:03}.cpp'.format(chunk_idx), 'w')
            cpp_file.write(verbatim_collation_tests_form.format(contents))
            chunk_idx += 1
            contents = ''
            line_idx = 0
        non_ignorable_line = non_ignorable_line[:-1]
        if not non_ignorable_line.startswith('#') and len(non_ignorable_line) != 0:
            comment_start = non_ignorable_line.find('#')
            non_ignorable_comment = ''
            if comment_start != -1:
                non_ignorable_comment = non_ignorable_line[comment_start + 1:].strip()
                non_ignorable_line = non_ignorable_line[:comment_start]
            if 'surrogate' in non_ignorable_comment:
                continue
            if 'noncharacter' in non_ignorable_comment:
                continue
            cps = map(lambda x: '0x' + x, non_ignorable_line.split(';')[0].split(' '))
            ces_match = collation_elements_regex.search(non_ignorable_comment)
            ces = ces_match.group(1).replace('|', '0000').split(' ')
            ces = ces[:-1]
            ces_non_ignorable = map(lambda x: '0x' + x, ces)

            (shifted_comment, ces_shifted) = shifted[tuple(cps)]

            contents += '''
TEST(collation, verbatim_{1:03}_{2:03})
{{
    uint32_t const cps[{6}] = {{ {5} }};

    // {3}
    uint32_t const ces_non_ignorable[{8}] = {{ {7} }};

    auto const non_ignorable = collate_for_tests(
        cps, cps + {6}, boost::text::variable_weighting::non_ignorable,
        boost::text::collation_strength::tertiary);

    EXPECT_EQ(non_ignorable.size(), {8});
    EXPECT_TRUE(boost::algorithm::equal(non_ignorable.begin(), non_ignorable.end(), ces_non_ignorable, ces_non_ignorable + {8}))
        << "from:     " << ce_dumper(cps)
        << "expected: " << ce_dumper(ces_non_ignorable)
        << "got:      " << ce_dumper(non_ignorable);

    // {4}
    uint32_t const ces_shifted[{10}] = {{ {9} }};

    auto const shifted = collate_for_tests(
        cps, cps + {6}, boost::text::variable_weighting::shifted,
        boost::text::collation_strength::quaternary);

    EXPECT_EQ(shifted.size(), {10});
    EXPECT_TRUE(boost::algorithm::equal(shifted.begin(), shifted.end(), ces_shifted, ces_shifted + {10}))
        << "from:     " << ce_dumper(cps)
        << "expected: " << ce_dumper(ces_shifted)
        << "got:      " << ce_dumper(shifted);
}}
'''.format(
    None, chunk_idx, line_idx,
    non_ignorable_line + '\n    // ' + non_ignorable_comment,
    non_ignorable_line + '\n    // ' + shifted_comment,
    ', '.join(cps), len(cps),
    ', '.join(ces_non_ignorable), len(ces_non_ignorable),
    ', '.join(ces_shifted), len(ces_shifted)
    )
            line_idx += 1

    if contents != '':
        cpp_file = open('verbatim_collation_test_{0:03}.cpp'.format(chunk_idx), 'w')
        cpp_file.write(verbatim_collation_tests_form.format(contents))

def generate_relative_collation_tests(filename, weighting):
    lines = open(filename, 'r').readlines()

    all_cps = []
    all_ranges = []
    chunk_idx = 0
    line_idx = 0 
    for line in lines:
        if line_idx == 25000:
            cps_string = ', '.join(map(lambda x: '0x' + x, all_cps))
            ranges_string = ', '.join(map(lambda x: '{{{}, {}}}'.format(x[0], x[1]), all_ranges))
            cpp_file = open('relative_collation_test_{0}_{1}.cpp'.format(weighting, chunk_idx), 'w')
            cpp_file.write(relative_collation_tests_form.format(cps_string, len(all_cps), ranges_string, len(all_ranges), weighting, chunk_idx))
            chunk_idx += 1
            all_cps = []
            all_ranges = []
            line_idx = 0
        line = line[:-1]
        if not line.startswith('#') and len(line) != 0:
            comment_start = line.find('#')
            comment = ''
            if comment_start != -1:
                comment = line[comment_start + 1:].strip()
                line = line[:comment_start]
            if 'surrogate' in comment:
                continue
            if 'noncharacter' in comment:
                continue
            cps = line.split(';')[0].split(' ')
            first = len(all_cps)
            all_cps += cps
            last = len(all_cps)
            all_ranges.append((first, last))
            line_idx += 1

    if line_idx != 0:
        cps_string = ', '.join(map(lambda x: '0x' + x, all_cps))
        ranges_string = ', '.join(map(lambda x: '{{{}, {}}}'.format(x[0], x[1]), all_ranges))
        cpp_file = open('relative_collation_test_{0}_{1}.cpp'.format(weighting, chunk_idx), 'w')
        cpp_file.write(relative_collation_tests_form.format(cps_string, len(all_cps), ranges_string, len(all_ranges), weighting, chunk_idx))

import sys
if '--perf' in sys.argv:
    cet = get_frac_uca_cet('FractionalUCA.txt')
    generate_lookup_perf_test(cet)
    generate_collation_perf_test(cet)
    exit(0)

#generate_verbatim_collation_tests('CollationTest_CLDR_NON_IGNORABLE.txt', 'CollationTest_CLDR_SHIFTED.txt')
generate_relative_collation_tests('CollationTest_CLDR_NON_IGNORABLE.txt', 'non_ignorable')
generate_relative_collation_tests('CollationTest_CLDR_SHIFTED.txt', 'shifted')
