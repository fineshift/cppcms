# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef CPPCMS_BOOST_PREPROCESSOR_SEQ_TO_TUPLE_HPP
# define CPPCMS_BOOST_PREPROCESSOR_SEQ_TO_TUPLE_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/seq/enum.hpp>
#
# /* BOOST_PP_SEQ_TO_TUPLE */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_SEQ_TO_TUPLE(seq) (CPPCMS_BOOST_PP_SEQ_ENUM(seq))
# else
#    define CPPCMS_BOOST_PP_SEQ_TO_TUPLE(seq) CPPCMS_BOOST_PP_SEQ_TO_TUPLE_I(seq)
#    define CPPCMS_BOOST_PP_SEQ_TO_TUPLE_I(seq) (CPPCMS_BOOST_PP_SEQ_ENUM(seq))
# endif
#
# endif
