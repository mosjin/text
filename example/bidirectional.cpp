#include <boost/text/bidirectional.hpp>
#include <boost/text/text.hpp>
#include <boost/text/rope.hpp>

#include <boost/config.hpp>

#include <iostream>


//[ bidi_line_break_extent_cpp11
struct extent_callable
{
    template<typename CPIter>
    int operator()(CPIter first, CPIter last) const noexcept
    {
        boost::text::grapheme_range<CPIter> range(first, last);
        return std::distance(range.begin(), range.end());
    }
};
//]

int main ()
{

{
//[ bidi_simple

// This is the Arabic text as it appears in Google translate, already
// right-to-left.  This is how we expect it to appear in our output below,
// after the bidirectional algorithm processes it.
boost::text::text const RTL_order_arabic = "مرحبا ، عالم ثنائي الاتجاه";

boost::text::text const memory_order_text =
    u8"When I type \"Hello, bidirectional world\" into Google translate "
    u8"English->Arabic, it produces \"هاجتالا يئانث ملاع ، ابحرم\".  I have no "
    u8"idea if it's correct.\n";

/* Prints:
When I type "Hello, bidirectional world" into Google translate English->Arabic, it produces "مرحبا ، عالم ثنائي الاتجاه".  I have no idea if it's correct.
*/
boost::text::rope bidirectional_text;
for (auto range : boost::text::bidirectional_subranges(memory_order_text)) {
    for (auto grapheme : range) {
        // We can take each grapheme and print it out directly ...
        std::cout << grapheme;
        // ... or we can insert it into a text to be used elsewhere.
        bidirectional_text.insert(bidirectional_text.end(), grapheme);
    }
}

// Prints same as the loop above.
std::cout << bidirectional_text;
//]
}

{
//[ bidi_with_line_breaks
boost::text::text const memory_order_text =
    u8"When I type \"Hello, bidirectional world\" into Google translate "
    u8"English->Arabic, it produces \"هاجتالا يئانث ملاع ، ابحرم\".  I have no "
    u8"idea if it's correct.\n";

#ifdef BOOST_NO_CXX14_GENERIC_LAMBDAS
// This is an out-of-line callable with a operator() member template.  It's
// just like the lambda below.
extent_callable extent;
#else
// The extent callable used in the line-breaking example took parameters of
// fixed type.  The bidirectional algorithm needs to call this using some of
// its own internal iterators, so the extent-callable it expects should be
// written as a template or a generic lambda.
auto const extent = [](auto first, auto last) {
    boost::text::grapheme_range<decltype(first)> range(first, last);
    return std::distance(range.begin(), range.end());
};
#endif

/* Prints:
************************************************************
When I type "Hello, bidirectional world" into Google 
translate English->Arabic, it produces "ثنائي الاتجاه 
مرحبا ، عالم".  I have no idea if it's correct.
************************************************************
*/
std::cout << boost::text::repeat("*", 60) << "\n";
for (auto range :
     boost::text::bidirectional_subranges(memory_order_text, 60, extent)) {
    for (auto grapheme : range) {
        std::cout << grapheme;
    }
    // With the example for line breaking, our predicate in this spot was
    // !hard_break().  In this case though, there are some subranges that have
    // no line breaks at all.  Since we don't want double line breaks, we
    // still don't add a line break after a hard_break().  That leaves the
    // need to break only after allowed breaks.
    if (range.allowed_break())
        std::cout << "\n";
}
std::cout << boost::text::repeat("*", 60) << "\n";
//]
}

}
