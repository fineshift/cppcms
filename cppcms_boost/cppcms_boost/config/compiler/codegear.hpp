//  (C) Copyright John Maddock 2001 - 2003.
//  (C) Copyright David Abrahams 2002 - 2003.
//  (C) Copyright Aleksey Gurtovoy 2002.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  CodeGear C++ compiler setup:

#if !defined( CPPCMS_BOOST_WITH_CODEGEAR_WARNINGS )
// these warnings occur frequently in optimized template code
# pragma warn -8004 // var assigned value, but never used
# pragma warn -8008 // condition always true/false
# pragma warn -8066 // dead code can never execute
# pragma warn -8104 // static members with ctors not threadsafe
# pragma warn -8105 // reference member in class without ctors
#endif
//
// versions check:
// last known and checked version is 0x610
#if (__CODEGEARC__ > 0x613)
#  if defined(CPPCMS_BOOST_ASSERT_CONFIG)
#     error "Unknown compiler version - please run the configure tests and report the results"
#  else
#     pragma message( "Unknown compiler version - please run the configure tests and report the results")
#  endif
#endif

// CodeGear C++ Builder 2009
#if (__CODEGEARC__ <= 0x613)
#  define CPPCMS_BOOST_FUNCTION_SCOPE_USING_DECLARATION_BREAKS_ADL
#  define CPPCMS_BOOST_NO_DEPENDENT_NESTED_DERIVATIONS
#  define CPPCMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS
#  define CPPCMS_BOOST_NO_PRIVATE_IN_AGGREGATE
#  define CPPCMS_BOOST_NO_TWO_PHASE_NAME_LOOKUP
#  define CPPCMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE
#  define CPPCMS_BOOST_NO_USING_TEMPLATE
   // we shouldn't really need this - but too many things choke
   // without it, this needs more investigation:
#  define CPPCMS_BOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS
#  define CPPCMS_BOOST_NO_TYPENAME_WITH_CTOR    // Cannot use typename keyword when making temporaries of a dependant type
#  define CPPCMS_BOOST_NO_NESTED_FRIENDSHIP     // TC1 gives nested classes access rights as any other member
#  define CPPCMS_BOOST_SP_NO_SP_CONVERTIBLE

// Temporary hack, until specific MPL preprocessed headers are generated
#  define CPPCMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS

#  ifdef NDEBUG
      // fix broken <cstring> so that Boost.test works:
#     include <cstring>
#     undef strcmp
#  endif
   // fix broken errno declaration:
#  include <errno.h>
#  ifndef errno
#     define errno errno
#  endif

#endif

//
// C++0x macros:
//
#define CPPCMS_BOOST_HAS_CHAR16_T
#define CPPCMS_BOOST_HAS_CHAR32_T
#define CPPCMS_BOOST_HAS_LONG_LONG
// #define BOOST_HAS_ALIGNOF
#define CPPCMS_BOOST_HAS_DECLTYPE
#define CPPCMS_BOOST_HAS_EXPLICIT_CONVERSION_OPS
// #define BOOST_HAS_RVALUE_REFS
#define CPPCMS_BOOST_HAS_SCOPED_ENUM
// #define BOOST_HAS_STATIC_ASSERT
#define CPPCMS_BOOST_HAS_STD_TYPE_TRAITS

#define CPPCMS_BOOST_NO_AUTO_DECLARATIONS
#define CPPCMS_BOOST_NO_AUTO_MULTIDECLARATIONS
#define CPPCMS_BOOST_NO_CONCEPTS
#define CPPCMS_BOOST_NO_CONSTEXPR
#define CPPCMS_BOOST_NO_DEFAULTED_FUNCTIONS
#define CPPCMS_BOOST_NO_DELETED_FUNCTIONS
#define CPPCMS_BOOST_NO_EXTERN_TEMPLATE
#define CPPCMS_BOOST_NO_FUNCTION_TEMPLATE_DEFAULT_ARGS
#define CPPCMS_BOOST_NO_INITIALIZER_LISTS
#define CPPCMS_BOOST_NO_LAMBDAS
#define CPPCMS_BOOST_NO_NULLPTR
#define CPPCMS_BOOST_NO_RAW_LITERALS
#define CPPCMS_BOOST_NO_RVALUE_REFERENCES
#define CPPCMS_BOOST_NO_SFINAE_EXPR
#define CPPCMS_BOOST_NO_STATIC_ASSERT
#define CPPCMS_BOOST_NO_TEMPLATE_ALIASES
#define CPPCMS_BOOST_NO_UNICODE_LITERALS
#define CPPCMS_BOOST_NO_VARIADIC_TEMPLATES

//
// TR1 macros:
//
#define CPPCMS_BOOST_HAS_TR1_HASH
#define CPPCMS_BOOST_HAS_TR1_TYPE_TRAITS
#define CPPCMS_BOOST_HAS_TR1_UNORDERED_MAP
#define CPPCMS_BOOST_HAS_TR1_UNORDERED_SET

#define CPPCMS_BOOST_HAS_MACRO_USE_FACET

#define CPPCMS_BOOST_NO_INITIALIZER_LISTS

// On non-Win32 platforms let the platform config figure this out:
#ifdef _WIN32
#  define CPPCMS_BOOST_HAS_STDINT_H
#endif

//
// __int64:
//
#if !defined(__STRICT_ANSI__)
#  define CPPCMS_BOOST_HAS_MS_INT64
#endif
//
// check for exception handling support:
//
#if !defined(_CPPUNWIND) && !defined(CPPCMS_BOOST_CPPUNWIND) && !defined(__EXCEPTIONS)
#  define CPPCMS_BOOST_NO_EXCEPTIONS
#endif
//
// all versions have a <dirent.h>:
//
#if !defined(__STRICT_ANSI__)
#  define CPPCMS_BOOST_HAS_DIRENT_H
#endif
//
// all versions support __declspec:
//
#if !defined(__STRICT_ANSI__)
#  define CPPCMS_BOOST_HAS_DECLSPEC
#endif
//
// ABI fixing headers:
//
#ifndef CPPCMS_BOOST_ABI_PREFIX
#  define CPPCMS_BOOST_ABI_PREFIX "cppcms_boost/config/abi/borland_prefix.hpp"
#endif
#ifndef CPPCMS_BOOST_ABI_SUFFIX
#  define CPPCMS_BOOST_ABI_SUFFIX "cppcms_boost/config/abi/borland_suffix.hpp"
#endif
//
// Disable Win32 support in ANSI mode:
//
#  pragma defineonoption CPPCMS_BOOST_DISABLE_WIN32 -A
//
// MSVC compatibility mode does some nasty things:
// TODO: look up if this doesn't apply to the whole 12xx range
//
#if defined(_MSC_VER) && (_MSC_VER <= 1200)
#  define CPPCMS_BOOST_NO_ARGUMENT_DEPENDENT_LOOKUP
#  define CPPCMS_BOOST_NO_VOID_RETURNS
#endif

#define CPPCMS_BOOST_COMPILER "CodeGear C++ version " CPPCMS_BOOST_STRINGIZE(__CODEGEARC__)

