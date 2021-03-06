#if !defined(BOOST_VMD_DETAIL_AFTER_IDENTIFIER_COMMON_HPP)
#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_COMMON_HPP

#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/comparison/not_equal.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/logical/bitor.hpp>
#include <boost/preprocessor/logical/nor.hpp>
#include <boost/preprocessor/logical/not.hpp>
#include <boost/preprocessor/seq/seq.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/preprocessor/variadic/elem.hpp>
#include <boost/preprocessor/variadic/size.hpp>
#include <boost/preprocessor/variadic/to_tuple.hpp>
#include <boost/vmd/empty.hpp>
#include <boost/vmd/identity.hpp>
#include <boost/vmd/is_begin_tuple.hpp>
#include <boost/vmd/is_empty.hpp>
#include <boost/vmd/tuple.hpp>
#include <boost/vmd/detail/is_empty_tuple.hpp>
#include <boost/vmd/detail/paren_or_empty.hpp>

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_IS_EMPTY_TUPLE_IRESULT(param) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_TUPLE(param), \
		BOOST_VMD_DETAIL_IS_EMPTY_TUPLE_SIZE, \
		BOOST_VMD_IDENTITY(0) \
		) \
	(param) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_EMPTY_TUPLE(keys) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_AFTER_IDENTIFIER_IS_EMPTY_TUPLE_IRESULT(keys)) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_HAS_KEYS(keys) \
	BOOST_PP_NOT \
		( \
		BOOST_PP_BITOR \
			( \
			BOOST_VMD_IS_EMPTY(keys), \
			BOOST_VMD_DETAIL_AFTER_IDENTIFIER_EMPTY_TUPLE(keys) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TAIL(state) \
	BOOST_PP_SEQ_TAIL(BOOST_PP_TUPLE_ELEM(4,state)) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_CAT(param,key) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_PAREN_OR_EMPTY(key), \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_JUST_PARAM, \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_DO_CAT \
		) \
	(param,key) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_JUST_PARAM(param,key) \
	param \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_DO_CAT(param,key) \
    	BOOST_PP_CAT \
    		( \
   			BOOST_VMD_MAP_, \
    		BOOST_PP_CAT \
    			( \
    			key, \
   				param \
    			) \
    		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_REST(state) \
	BOOST_VMD_DETAIL_AFTER_IDENTIFIER_CAT \
		( \
		BOOST_PP_TUPLE_ELEM(0,state), \
		BOOST_PP_TUPLE_ELEM \
			( \
			BOOST_PP_TUPLE_ELEM(2,state), \
			BOOST_PP_TUPLE_ELEM(1,state) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_FOUND(state) \
	(BOOST_PP_INC(BOOST_PP_TUPLE_ELEM(2,state)),BOOST_VMD_DETAIL_AFTER_IDENTIFIER_REST(state)) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_CONTINUE(state) \
	(0,) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_CINFO_DATA(...) \
	BOOST_PP_VARIADIC_ELEM(1,__VA_ARGS__) \
/**/

#if BOOST_VMD_MSVC

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_FIRST_ARG(keys) \
	BOOST_PP_CAT \
		( \
		BOOST_VMD_ASSERT_IS_TUPLE(keys), \
		keys \
		) \
/**/

#else

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_FIRST_ARG(keys) \
    BOOST_VMD_ASSERT_IS_TUPLE(keys) \
    keys \
/**/

#endif

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_TUPLE(keys) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_BEGIN_TUPLE(keys), \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_FIRST_ARG, \
		BOOST_PP_VARIADIC_TO_TUPLE \
		) \
	(keys) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_PRED(d,state) \
	BOOST_PP_NOR \
		( \
		BOOST_PP_TUPLE_ELEM \
			( \
			0, \
			BOOST_PP_TUPLE_ELEM(3,state) \
			), \
		BOOST_PP_EQUAL \
			( \
			BOOST_PP_TUPLE_ELEM(2,state), \
			BOOST_PP_TUPLE_SIZE \
				( \
				BOOST_PP_TUPLE_ELEM(1,state) \
				) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_CINFO(d,...) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_NOT_EQUAL \
			( \
			BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), \
			1 \
			), \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_CINFO_DATA, \
		BOOST_VMD_EMPTY \
		) \
	(__VA_ARGS__) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_NOT_FOUND(...) \
	(0,) \
/**/

#endif /* BOOST_VMD_DETAIL_AFTER_IDENTIFIER_COMMON_HPP */
