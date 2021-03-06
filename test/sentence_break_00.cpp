// Warning! This file is autogenerated.
#include <boost/text/sentence_break.hpp>

#include <gtest/gtest.h>

#include <algorithm>


TEST(sentence, breaks_0)
{
    // ÷ 0001 × 0001 ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [998.0] <START OF HEADING> (Other) ÷ [0.3]
    {
        std::array<uint32_t, 2> cps = {{ 0x1, 0x1 }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
    }


    // ÷ 0001 × 0308 × 0001 ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [5.0] COMBINING DIAERESIS (Extend_FE) × [998.0] <START OF HEADING> (Other) ÷ [0.3]
    {
        std::array<uint32_t, 3> cps = {{ 0x1, 0x308, 0x1 }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 3, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
    }


    // ÷ 0001 × 000D ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [998.0] <CARRIAGE RETURN (CR)> (CR) ÷ [0.3]
    {
        std::array<uint32_t, 2> cps = {{ 0x1, 0xd }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
    }


    // ÷ 0001 × 0308 × 000D ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [5.0] COMBINING DIAERESIS (Extend_FE) × [998.0] <CARRIAGE RETURN (CR)> (CR) ÷ [0.3]
    {
        std::array<uint32_t, 3> cps = {{ 0x1, 0x308, 0xd }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 3, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
    }


    // ÷ 0001 × 000A ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [998.0] <LINE FEED (LF)> (LF) ÷ [0.3]
    {
        std::array<uint32_t, 2> cps = {{ 0x1, 0xa }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
    }


    // ÷ 0001 × 0308 × 000A ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [5.0] COMBINING DIAERESIS (Extend_FE) × [998.0] <LINE FEED (LF)> (LF) ÷ [0.3]
    {
        std::array<uint32_t, 3> cps = {{ 0x1, 0x308, 0xa }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 3, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
    }


    // ÷ 0001 × 0085 ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [998.0] <NEXT LINE (NEL)> (Sep) ÷ [0.3]
    {
        std::array<uint32_t, 2> cps = {{ 0x1, 0x85 }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
    }


    // ÷ 0001 × 0308 × 0085 ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [5.0] COMBINING DIAERESIS (Extend_FE) × [998.0] <NEXT LINE (NEL)> (Sep) ÷ [0.3]
    {
        std::array<uint32_t, 3> cps = {{ 0x1, 0x308, 0x85 }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 3, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
    }


    // ÷ 0001 × 0009 ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [998.0] <CHARACTER TABULATION> (Sp) ÷ [0.3]
    {
        std::array<uint32_t, 2> cps = {{ 0x1, 0x9 }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
    }


    // ÷ 0001 × 0308 × 0009 ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [5.0] COMBINING DIAERESIS (Extend_FE) × [998.0] <CHARACTER TABULATION> (Sp) ÷ [0.3]
    {
        std::array<uint32_t, 3> cps = {{ 0x1, 0x308, 0x9 }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 3, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
    }


    // ÷ 0001 × 0061 ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [998.0] LATIN SMALL LETTER A (Lower) ÷ [0.3]
    {
        std::array<uint32_t, 2> cps = {{ 0x1, 0x61 }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
    }


    // ÷ 0001 × 0308 × 0061 ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [5.0] COMBINING DIAERESIS (Extend_FE) × [998.0] LATIN SMALL LETTER A (Lower) ÷ [0.3]
    {
        std::array<uint32_t, 3> cps = {{ 0x1, 0x308, 0x61 }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 3, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
    }


    // ÷ 0001 × 0041 ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [998.0] LATIN CAPITAL LETTER A (Upper) ÷ [0.3]
    {
        std::array<uint32_t, 2> cps = {{ 0x1, 0x41 }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
    }


    // ÷ 0001 × 0308 × 0041 ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [5.0] COMBINING DIAERESIS (Extend_FE) × [998.0] LATIN CAPITAL LETTER A (Upper) ÷ [0.3]
    {
        std::array<uint32_t, 3> cps = {{ 0x1, 0x308, 0x41 }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 3, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
    }


    // ÷ 0001 × 01BB ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [998.0] LATIN LETTER TWO WITH STROKE (OLetter) ÷ [0.3]
    {
        std::array<uint32_t, 2> cps = {{ 0x1, 0x1bb }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
    }


    // ÷ 0001 × 0308 × 01BB ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [5.0] COMBINING DIAERESIS (Extend_FE) × [998.0] LATIN LETTER TWO WITH STROKE (OLetter) ÷ [0.3]
    {
        std::array<uint32_t, 3> cps = {{ 0x1, 0x308, 0x1bb }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 3, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
    }


    // ÷ 0001 × 0030 ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [998.0] DIGIT ZERO (Numeric) ÷ [0.3]
    {
        std::array<uint32_t, 2> cps = {{ 0x1, 0x30 }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
    }


    // ÷ 0001 × 0308 × 0030 ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [5.0] COMBINING DIAERESIS (Extend_FE) × [998.0] DIGIT ZERO (Numeric) ÷ [0.3]
    {
        std::array<uint32_t, 3> cps = {{ 0x1, 0x308, 0x30 }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 3, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
    }


    // ÷ 0001 × 002E ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [998.0] FULL STOP (ATerm) ÷ [0.3]
    {
        std::array<uint32_t, 2> cps = {{ 0x1, 0x2e }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
    }


    // ÷ 0001 × 0308 × 002E ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [5.0] COMBINING DIAERESIS (Extend_FE) × [998.0] FULL STOP (ATerm) ÷ [0.3]
    {
        std::array<uint32_t, 3> cps = {{ 0x1, 0x308, 0x2e }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 3, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
    }


    // ÷ 0001 × 0021 ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [998.0] EXCLAMATION MARK (STerm) ÷ [0.3]
    {
        std::array<uint32_t, 2> cps = {{ 0x1, 0x21 }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
    }


    // ÷ 0001 × 0308 × 0021 ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [5.0] COMBINING DIAERESIS (Extend_FE) × [998.0] EXCLAMATION MARK (STerm) ÷ [0.3]
    {
        std::array<uint32_t, 3> cps = {{ 0x1, 0x308, 0x21 }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 3, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
    }


    // ÷ 0001 × 0022 ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [998.0] QUOTATION MARK (Close) ÷ [0.3]
    {
        std::array<uint32_t, 2> cps = {{ 0x1, 0x22 }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
    }


    // ÷ 0001 × 0308 × 0022 ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [5.0] COMBINING DIAERESIS (Extend_FE) × [998.0] QUOTATION MARK (Close) ÷ [0.3]
    {
        std::array<uint32_t, 3> cps = {{ 0x1, 0x308, 0x22 }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 3, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
    }


    // ÷ 0001 × 002C ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [998.0] COMMA (SContinue) ÷ [0.3]
    {
        std::array<uint32_t, 2> cps = {{ 0x1, 0x2c }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 2);
    }


    // ÷ 0001 × 0308 × 002C ÷	
    // ÷ [0.2] <START OF HEADING> (Other) × [5.0] COMBINING DIAERESIS (Extend_FE) × [998.0] COMMA (SContinue) ÷ [0.3]
    {
        std::array<uint32_t, 3> cps = {{ 0x1, 0x308, 0x2c }};
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 0, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 1, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 2, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
        EXPECT_EQ(boost::text::prev_sentence_break(cps.begin(), cps.begin() + 3, cps.end()) - cps.begin(), 0);
        EXPECT_EQ(boost::text::next_sentence_break(cps.begin() + 0, cps.end()) - cps.begin(), 3);
    }


}
