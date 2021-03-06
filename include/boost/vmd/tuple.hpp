#if !defined(BOOST_VMD_TUPLE_HPP)
#define BOOST_VMD_TUPLE_HPP

#include <boost/vmd/detail/setup.hpp>

#if BOOST_PP_VARIADICS

#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/vmd/is_begin_tuple.hpp>
#include <boost/vmd/detail/is_entire.hpp>
#include <boost/vmd/detail/tuple.hpp>
#include <boost/vmd/detail/empty_result.hpp>

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/** \brief Expands to a tuple of the beginning tuple, and the preprocessor tokens after the beginning tuple, of a macro parameter.

    param = a macro parameter.

    returns   = the result is a tuple of two elements.
    			If the param does not start with a tuple, both elements of the tuple are empty.
   				If the param does start with a tuple, the first element is the beginning tuple
   				and the second element is the preprocessor tokens after the beginning tuple.
    
*/
# define BOOST_VMD_TUPLE(param) \
    BOOST_PP_IIF \
      ( \
      BOOST_VMD_IS_BEGIN_TUPLE(param), \
      BOOST_VMD_DETAIL_AFTER_TUPLE, \
      BOOST_VMD_DETAIL_EMPTY_RESULT \
      ) \
    (param) \
/**/

/** \brief Expands to the beginning tuple of a macro parameter.

    param = a macro parameter.

    returns = the preprocessor tokens forming the beginning tuple.
    		  If the param does not start with a tuple,
    		  the return value is empty.
    
*/
# define BOOST_VMD_BEGIN_TUPLE(param) \
	BOOST_PP_TUPLE_ELEM \
		( \
		0, \
		BOOST_VMD_TUPLE(param) \
		) \
/**/

/** \brief Expands to the preprocessor tokens after the beginning tuple of a macro parameter.

    parameter = a macro parameter.

    returns   = expands to the preprocessor tokens after the tuple.
    			If the tuple is not found, expands to nothing.
    
*/
#define BOOST_VMD_AFTER_TUPLE(parameter) \
	BOOST_PP_TUPLE_ELEM \
		( \
		1, \
		BOOST_VMD_TUPLE(parameter) \
		) \
/**/

/** \def BOOST_VMD_IS_TUPLE(param)

    \brief Tests whether a parameter is a Boost PP tuple.

    The macro checks to see if a parameter is a Boost PP tuple.
    A Boost PP tuple is a parameter enclosed by a set of parenthesis
    with no prerocessing tokens before or after the parenthesis.
    
    param = a preprocessor parameter

    returns = 1 if the param is a Boost PP tuple.
              0 if it is not.
              
*/

#define BOOST_VMD_IS_TUPLE(param) \
	BOOST_VMD_DETAIL_IS_ENTIRE \
		( \
		BOOST_VMD_TUPLE(param) \
		) \
/**/

/** \def BOOST_VMD_ASSERT_IS_TUPLE(tuple)

    \brief Asserts that the parameter is a pplib tuple.

    The macro checks that the parameter is a pplib tuple.
    If it is not a pplib tuple, it forces a compiler error.
    
    The macro works through variadic macro support.
    
    The macro normally checks for a pplib tuple only in 
    debug mode. However an end-user can force the macro 
    to check or not check by defining the macro 
    BOOST_VMD_ASSERT_DATA to 1 or 0 respectively.

    tuple = a possible Boost pplib tuple.

    returns = Normally the macro returns nothing. 
    
              If the parameter is a pplib tuple, nothing is 
              output.
              
              For VC++, because there is no sure way of forcing  
              a compiler error from within a macro without producing
              output, if the parameter is not a pplib tuple the 
              macro forces a compiler error by outputting invalid C++.
              
              For all other compilers a compiler error is forced 
              without producing output if the parameter is not a 
              pplib tuple.
              
*/

#if !BOOST_VMD_ASSERT_DATA

#define BOOST_VMD_ASSERT_IS_TUPLE(tuple)

#else

#include <boost/vmd/assert.hpp>

#define BOOST_VMD_ASSERT_IS_TUPLE(tuple) \
   BOOST_VMD_ASSERT \
     ( \
     BOOST_VMD_IS_TUPLE(tuple), \
     BOOST_VMD_ASSERT_IS_TUPLE_ERROR \
     ) \
/**/

#endif /* BOOST_VMD_ASSERT_DATA */

#endif /* BOOST_PP_VARIADICS */
#endif /* BOOST_VMD_TUPLE_HPP */
