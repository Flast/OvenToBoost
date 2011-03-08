// Boost.Range 2.0 Extension library
// via PStade Oven Library
//
// Copyright Akira Takahashi 2011.
// Copyright Shunsuke Sogame 2005-2007.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_RANGE_REGULAR_INCLUDE
#define BOOST_RANGE_REGULAR_INCLUDE

#include "./detail/indirect_functor.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/mpl/identity.hpp>

namespace boost { namespace range {

namespace result_of {

template <class F>
struct regular : boost::mpl::identity<detail::indirect_functor<boost::shared_ptr<F> > > {};

} // namespace result_of

template <class F>
inline typename result_of::regular<F>::type regular(F f)
{
    return typename result_of::regular<F>::type(boost::shared_ptr<F>(new F(f)));
}

} // namespace range

using range::regular;

} // namespace boost

#endif // BOOST_RANGE_REGULAR_INCLUDE

