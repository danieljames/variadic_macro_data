#if !defined(BOOST_VMD_IS_NUMBER_HPP)
#define BOOST_VMD_IS_NUMBER_HPP

#include <boost/vmd/detail/setup.hpp>

#if BOOST_PP_VARIADICS

#include <boost/vmd/detail/is_number.hpp>

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/** \def BOOST_VMD_IS_NUMBER(ppident)

    \brief Tests whether a parameter is a Boost PP number.

    The macro checks to see if a parameter is a Boost PP number.
    A Boost PP number is a value from 0 to 256.
    
    ppident = a preprocessor identifier

    returns = 1 if the param is a Boost PP number, 
              0 if it is not.
              
    The macro works through variadic macro support.
    The ppident can be either:
    
    1) A preprocessor identifier, alphanumeric or underscore characters.
    2) An empty value, returns 0.
    3) A set of beginning parens, returns 0.
    
    If it is not one of these possibilities a compiler error will occur.
    
*/

#define BOOST_VMD_IS_NUMBER(ppident) \
	BOOST_VMD_DETAIL_IS_NUMBER(ppident) \
/**/

#if !BOOST_VMD_ASSERT_DATA

#define BOOST_VMD_ASSERT_IS_NUMBER(ppident)

#else

#include <boost/vmd/assert.hpp>

#define BOOST_VMD_ASSERT_IS_NUMBER(ppident) \
    BOOST_VMD_ASSERT \
      	( \
      	BOOST_VMD_IS_NUMBER(ppident), \
      	BOOST_VMD_IS_NUMBER_ASSERT_ERROR \
      	) \
/**/

#endif // !BOOST_VMD_ASSERT_DATA

#endif /* BOOST_PP_VARIADICS */
#endif /* BOOST_VMD_IS_NUMBER_HPP */
