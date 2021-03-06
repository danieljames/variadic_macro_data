#if !defined(BOOST_VMD_DETAIL_AFTER_IDENTIFIER_RE_HPP)
#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_RE_HPP

#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/comparison/not_equal.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/control/while.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/seq.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/variadic/elem.hpp>
#include <boost/vmd/empty.hpp>
#include <boost/vmd/identity.hpp>
#include <boost/vmd/detail/paren_or_empty_or_number.hpp>
#include <boost/vmd/detail/paren_or_empty_or_simple_number.hpp>
#include <boost/vmd/detail/after_identifier_common.hpp>

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_RECURSE_RESULT_3(d,state) \
	BOOST_VMD_DETAIL_AFTER_IDENTIFIER_2 \
		( \
		d, \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_REST(state), \
		BOOST_PP_SEQ_ELEM(0,BOOST_PP_TUPLE_ELEM(4,state)), \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TAIL(state), \
		BOOST_PP_TUPLE_ELEM(5,state) \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_RECURSE_RESULT_2(d,state) \
	BOOST_VMD_DETAIL_AFTER_IDENTIFIER_1 \
		( \
		d, \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_REST(state), \
		BOOST_PP_SEQ_ELEM(0,BOOST_PP_TUPLE_ELEM(4,state)), \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TAIL(state), \
		BOOST_PP_TUPLE_ELEM(5,state) \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_RECURSE_RESULT_1(d,state) \
	BOOST_VMD_DETAIL_AFTER_IDENTIFIER_0 \
		( \
		d, \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_REST(state), \
		BOOST_PP_SEQ_ELEM(0,BOOST_PP_TUPLE_ELEM(4,state)), \
		BOOST_VMD_EMPTY(state), \
		BOOST_PP_TUPLE_ELEM(5,state) \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_RECURSE_3(d,state) \
	BOOST_PP_NOT_EQUAL \
		( \
		BOOST_PP_TUPLE_ELEM \
			( \
			0, \
			BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_RECURSE_RESULT_3(d,state) \
			), \
		0 \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_RECURSE_2(d,state) \
	BOOST_PP_NOT_EQUAL \
		( \
		BOOST_PP_TUPLE_ELEM \
			( \
			0, \
			BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_RECURSE_RESULT_2(d,state) \
			), \
		0 \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_RECURSE_1(d,state) \
	BOOST_PP_NOT_EQUAL \
		( \
		BOOST_PP_TUPLE_ELEM \
			( \
			0, \
			BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_RECURSE_RESULT_1(d,state) \
			), \
		0 \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TEST_3_IRESULT(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_PAREN_OR_EMPTY_OR_SIMPLE_NUMBER \
			( \
			BOOST_VMD_DETAIL_AFTER_IDENTIFIER_REST(state) \
			), \
		BOOST_VMD_IDENTITY(1), \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_RECURSE_3 \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TEST_2_IRESULT(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_PAREN_OR_EMPTY_OR_SIMPLE_NUMBER \
			( \
			BOOST_VMD_DETAIL_AFTER_IDENTIFIER_REST(state) \
			), \
		BOOST_VMD_IDENTITY(1), \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_RECURSE_2 \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TEST_1_IRESULT(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_PAREN_OR_EMPTY_OR_SIMPLE_NUMBER \
			( \
			BOOST_VMD_DETAIL_AFTER_IDENTIFIER_REST(state) \
			), \
		BOOST_VMD_IDENTITY(1), \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_RECURSE_1 \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TEST_3(d,state) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TEST_3_IRESULT(d,state)) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TEST_2(d,state) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TEST_2_IRESULT(d,state)) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TEST_1(d,state) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TEST_1_IRESULT(d,state)) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TEST_0(state) \
	BOOST_VMD_DETAIL_PAREN_OR_EMPTY_OR_NUMBER \
		( \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_REST(state), \
		BOOST_PP_TUPLE_ELEM(5,state) \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_3(d,state) \
	( \
	BOOST_PP_TUPLE_ELEM(0,state), \
	BOOST_PP_TUPLE_ELEM(1,state), \
	BOOST_PP_INC(BOOST_PP_TUPLE_ELEM(2,state)), \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TEST_3(d,state), \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_FOUND, \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_CONTINUE \
		) \
	(state), \
	BOOST_PP_TUPLE_ELEM(4,state), \
	BOOST_PP_TUPLE_ELEM(5,state) \
	) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_2(d,state) \
	( \
	BOOST_PP_TUPLE_ELEM(0,state), \
	BOOST_PP_TUPLE_ELEM(1,state), \
	BOOST_PP_INC(BOOST_PP_TUPLE_ELEM(2,state)), \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TEST_2(d,state), \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_FOUND, \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_CONTINUE \
		) \
	(state), \
	BOOST_PP_TUPLE_ELEM(4,state), \
	BOOST_PP_TUPLE_ELEM(5,state) \
	) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_1(d,state) \
	( \
	BOOST_PP_TUPLE_ELEM(0,state), \
	BOOST_PP_TUPLE_ELEM(1,state), \
	BOOST_PP_INC(BOOST_PP_TUPLE_ELEM(2,state)), \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TEST_1(d,state), \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_FOUND, \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_CONTINUE \
		) \
	(state), \
	BOOST_PP_TUPLE_ELEM(4,state), \
	BOOST_PP_TUPLE_ELEM(5,state) \
	) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_0(d,state) \
	( \
	BOOST_PP_TUPLE_ELEM(0,state), \
	BOOST_PP_TUPLE_ELEM(1,state), \
	BOOST_PP_INC(BOOST_PP_TUPLE_ELEM(2,state)), \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_TEST_0(state), \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_FOUND, \
		BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_CONTINUE \
		) \
	(state), \
	BOOST_PP_TUPLE_ELEM(4,state), \
	BOOST_PP_TUPLE_ELEM(5,state) \
	) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_3(d,parameter,...) \
	BOOST_PP_TUPLE_ELEM \
		( \
		3, \
		BOOST_PP_WHILE_ ## d \
			( \
			BOOST_VMD_DETAIL_AFTER_IDENTIFIER_PRED, \
			BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_3, \
				( \
				parameter, \
				BOOST_VMD_DETAIL_AFTER_IDENTIFIER_TUPLE \
					( \
					BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__) \
					), \
				0, \
				(0,), \
				BOOST_VMD_DETAIL_AFTER_IDENTIFIER_CINFO(d,__VA_ARGS__), \
				BOOST_PP_VARIADIC_ELEM(2,__VA_ARGS__) \
				) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_2(d,parameter,...) \
	BOOST_PP_TUPLE_ELEM \
		( \
		3, \
		BOOST_PP_WHILE_ ## d \
			( \
			BOOST_VMD_DETAIL_AFTER_IDENTIFIER_PRED, \
			BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_2, \
				( \
				parameter, \
				BOOST_VMD_DETAIL_AFTER_IDENTIFIER_TUPLE \
					( \
					BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__) \
					), \
				0, \
				(0,), \
				BOOST_VMD_DETAIL_AFTER_IDENTIFIER_CINFO(d,__VA_ARGS__), \
				BOOST_PP_VARIADIC_ELEM(2,__VA_ARGS__) \
				) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_1(d,parameter,...) \
	BOOST_PP_TUPLE_ELEM \
		( \
		3, \
		BOOST_PP_WHILE_ ## d \
			( \
			BOOST_VMD_DETAIL_AFTER_IDENTIFIER_PRED, \
			BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_1, \
				( \
				parameter, \
				BOOST_VMD_DETAIL_AFTER_IDENTIFIER_TUPLE \
					( \
					BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__) \
					), \
				0, \
				(0,), \
				BOOST_VMD_DETAIL_AFTER_IDENTIFIER_CINFO(d,__VA_ARGS__), \
				BOOST_PP_VARIADIC_ELEM(2,__VA_ARGS__) \
				) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_IDENTIFIER_0(d,parameter,...) \
	BOOST_PP_TUPLE_ELEM \
		( \
		3, \
		BOOST_PP_WHILE_ ## d \
			( \
			BOOST_VMD_DETAIL_AFTER_IDENTIFIER_PRED, \
			BOOST_VMD_DETAIL_AFTER_IDENTIFIER_OP_0, \
				( \
				parameter, \
				BOOST_VMD_DETAIL_AFTER_IDENTIFIER_TUPLE \
					( \
					BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__) \
					), \
				0, \
				(0,), \
				BOOST_PP_GEN_EMPTY(__VA_ARGS__), \
				BOOST_PP_VARIADIC_ELEM(2,__VA_ARGS__) \
				) \
			) \
		) \
/**/

#endif /* BOOST_VMD_DETAIL_AFTER_IDENTIFIER_RE_HPP */
