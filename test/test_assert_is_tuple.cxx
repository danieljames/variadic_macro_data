#if defined(BOOST_VMD_TEST_GENERAL_HEADER)
#include <boost/vmd/vmd.hpp>
#else
#include <boost/vmd/tuple.hpp>
#endif
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
#if BOOST_PP_VARIADICS

  #define A_TUPLE (*,#,zz)
  #define A_TUPLE2 (*,#,(zz,44,(e7)))
  #define AN_ARRAY (4,(5,7,f,x))
  #define A_LIST (e,(g,(&,BOOST_PP_NIL)))
  
#if !BOOST_VMD_MSVC_V8  

  #define AN_EMPTY_TUPLE ()
  
#endif

  BOOST_VMD_ASSERT_IS_TUPLE((t,3,e,2))
  BOOST_VMD_ASSERT_IS_TUPLE(((y,s,w),3,e,2))
  BOOST_VMD_ASSERT_IS_TUPLE(A_TUPLE)
  BOOST_VMD_ASSERT_IS_TUPLE(A_TUPLE2)
  BOOST_VMD_ASSERT_IS_TUPLE(AN_ARRAY)
  BOOST_VMD_ASSERT_IS_TUPLE(A_LIST)
  
#if !BOOST_VMD_MSVC_V8  

  BOOST_VMD_ASSERT_IS_TUPLE(())
  BOOST_VMD_ASSERT_IS_TUPLE(AN_EMPTY_TUPLE)
  
#endif

#endif

  return boost::report_errors();
  
  }
