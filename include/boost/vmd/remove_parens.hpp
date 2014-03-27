#if !defined(BOOST_VMD_REMOVE_PARENS_HPP)
#define BOOST_VMD_REMOVE_PARENS_HPP

#include <boost/vmd/detail/setup.hpp>

#if BOOST_PP_VARIADICS

#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/facilities/identity.hpp>
#include <boost/vmd/is_begin_tuple.hpp>
#include <boost/vmd/detail/remove_parens.hpp>

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/** \brief Removes the set of parens from the start of a parameter if it has any.

    param = a macro parameter.

    returns = the parameter with the beginning set of parens removed.
              If the parameter has no beginning set of parameters, the
              parameter is returned as is. If there are further sets of 
              parens after the beginning set of parameters, they are not
              removed.
    
*/
#define BOOST_VMD_REMOVE_PARENS(param) \
    BOOST_PP_IIF \
      ( \
      BOOST_VMD_IS_BEGIN_TUPLE(param), \
      BOOST_VMD_DETAIL_REMOVE_PARENS_EXEC, \
      BOOST_PP_IDENTITY \
      ) \
    (param)() \
/**/

#endif /* BOOST_PP_VARIADICS */
#endif /* BOOST_VMD_REMOVE_PARENS_HPP */
