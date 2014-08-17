// Boost.Range 2.0 Extension library
// via PStade Oven Library
//
// Copyright Kohei Takahashi 2014.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include "mock_range.hpp"
#include <boost/range/adaptor/memoized.hpp>

int main(int, const char**)
{
    using boost::range::unit_test::mock_const_range;
    using boost::adaptors::memoized;

    // This next line should fail when Boost.Range concept checking is
    // enabled since the adaptor takes at least a SinglePassRange.
    return (mock_const_range<boost::incrementable_traversal_tag>() | memoized).front();
}