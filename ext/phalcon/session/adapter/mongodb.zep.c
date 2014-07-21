
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Session\Adapter\MongoDB
 *
 * This adapter stores sessions in MongoDB
 *
 *<code>
 * $session = new \Phalcon\Session\Adapter\MongoDB(array(
 *    "collection" => MongoCollection $collection
 * ));
 *
 * $session->start();
 *
 * $session->set("var", "some-value");
 *
 * echo $session->get("var");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_MongoDB) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Session\\Adapter, MongoDB, phalcon, session_adapter_mongodb, phalcon_session_adapter_ce, phalcon_session_adapter_mongodb_method_entry, 0);

	/**
	 * Current session data
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_session_adapter_mongodb_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \MongoId
	 */
	zend_declare_property_null(phalcon_session_adapter_mongodb_ce, SL("_user"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \MongoCollection
	 */
	zend_declare_property_null(phalcon_session_adapter_mongodb_ce, SL("_collection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_session_adapter_mongodb_ce TSRMLS_CC, 1, phalcon_session_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Current session data
 *
 * @var string
 */
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, getData) {


	RETURN_MEMBER(this_ptr, "_data");

}

/**
 * @var \MongoId
 */
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, getUser) {


	RETURN_MEMBER(this_ptr, "_user");

}

/**
 * @var \MongoId
 */
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, setUser) {

	zval *user;

	zephir_fetch_params(0, 1, 0, &user);



	zephir_update_property_this(this_ptr, SL("_user"), user TSRMLS_CC);

}

/**
 * @var \MongoCollection
 */
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, getCollection) {


	RETURN_MEMBER(this_ptr, "_collection");

}

/**
 * Phalcon\Session\Adapter\MongoDB constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, __construct) {

	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1, *_3, *_4, *_5, *_6, *_7;
	zval *options = NULL, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(options) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_session_exception_ce, "Options must be an Array", "phalcon/session/adapter/mongodb.zep", 66);
		return;
	}
	if (!(zephir_array_isset_string(options, SS("collection")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_session_exception_ce, "The parameter 'collection' is required and has to be an instance of \\MongoCollection", "phalcon/session/adapter/mongodb.zep", 70);
		return;
	}
	zephir_array_fetch_string(&_0, options, SL("collection"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_collection"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 3);
	zephir_array_fast_append(_1, this_ptr);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "open", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 3);
	zephir_array_fast_append(_3, this_ptr);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "close", 1);
	zephir_array_fast_append(_3, _2);
	ZEPHIR_INIT_VAR(_4);
	array_init_size(_4, 3);
	zephir_array_fast_append(_4, this_ptr);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "read", 1);
	zephir_array_fast_append(_4, _2);
	ZEPHIR_INIT_VAR(_5);
	array_init_size(_5, 3);
	zephir_array_fast_append(_5, this_ptr);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "save", 1);
	zephir_array_fast_append(_5, _2);
	ZEPHIR_INIT_VAR(_6);
	array_init_size(_6, 3);
	zephir_array_fast_append(_6, this_ptr);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "destroy", 1);
	zephir_array_fast_append(_6, _2);
	ZEPHIR_INIT_VAR(_7);
	array_init_size(_7, 3);
	zephir_array_fast_append(_7, this_ptr);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "gc", 1);
	zephir_array_fast_append(_7, _2);
	ZEPHIR_CALL_FUNCTION(NULL, "session_set_save_handler", NULL, _1, _3, _4, _5, _6, _7);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_session_adapter_mongodb_ce, this_ptr, "__construct", &_8, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return bool
 */
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, open) {


	RETURN_BOOL(1);

}

/**
 * @return bool
 */
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, close) {


	RETURN_BOOL(1);

}

/**
 * {@inheritdoc}
 *
 * @param string sessionId
 * @return mixed
 */
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, read) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, *sessionData = NULL, *_0 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 2);
	zephir_array_update_string(&_1, SL("_id"), &sessionId, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&sessionData, _0, "findone", NULL, _1);
	zephir_check_call_status();
	if (zephir_array_isset_string(sessionData, SS("user"))) {
		zephir_array_fetch_string(&_2, sessionData, SL("user"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setuser", NULL, _2);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(sessionData, SS("data"))) {
		zephir_array_fetch_string(&_2, sessionData, SL("data"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_data"), _2 TSRMLS_CC);
		RETURN_MM_MEMBER(this_ptr, "_data");
	}
	RETURN_MM_STRING("", 1);

}

/**
 * {@inheritdoc}
 *
 * @param mixed sessionId
 * @param mixed data
 */
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *document;
	zval *sessionId = NULL, *data = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &sessionId, &data);

	if (!sessionId) {
		sessionId = ZEPHIR_GLOBAL(global_null);
	}
	if (!data) {
		ZEPHIR_INIT_VAR(data);
		ZVAL_STRING(data, "", 1);
	}
	ZEPHIR_INIT_VAR(document);
	array_init(document);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _0, "save", NULL, document);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * {@inheritdoc}
 *
 * @param  string  session_id
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, destroy) {

	zend_bool _2;
	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *session_id = NULL, *remove = NULL, *_0 = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &session_id);

	if (!session_id) {
		ZEPHIR_CPY_WRT(session_id, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(session_id);
	}


	if (Z_TYPE_P(session_id) == IS_NULL) {
		ZEPHIR_CALL_FUNCTION(&session_id, "session_id", NULL);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_data"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 2);
	zephir_array_update_string(&_1, SL("_id"), &session_id, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&remove, _0, "remove", NULL, _1);
	zephir_check_call_status();
	_2 = zephir_array_isset_string(remove, SS("ok"));
	if (_2) {
		ZEPHIR_OBS_VAR(_3);
		zephir_array_fetch_string(&_3, remove, SL("ok"), PH_NOISY TSRMLS_CC);
		_2 = zephir_get_boolval(_3);
	}
	RETURN_MM_BOOL(_2);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, gc) {

	zend_bool _8;
	zval *_6;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_0, *_2, *_4;
	zval *lifetime = NULL, *minAge, *minAgeMongo, *query, *remove = NULL, *_1, *_3, *_5 = NULL, *_7 = NULL, *_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &lifetime);

	if (!lifetime) {
		ZEPHIR_INIT_VAR(lifetime);
		ZVAL_LONG(lifetime, 86400);
	}


	ZEPHIR_INIT_VAR(minAge);
	_0 = zend_fetch_class(SL("DateTime"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(minAge, _0);
	ZEPHIR_CALL_METHOD(NULL, minAge, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	_2 = zend_fetch_class(SL("DateInterval"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_1, _2);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, "PT", lifetime, "S");
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, minAge, "sub", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(minAgeMongo);
	_4 = zend_fetch_class(SL("MongoDate"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(minAgeMongo, _4);
	ZEPHIR_CALL_METHOD(&_5, minAge, "gettimestamp",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, minAgeMongo, "__construct", NULL, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(query);
	array_init_size(query, 2);
	ZEPHIR_INIT_VAR(_6);
	array_init_size(_6, 2);
	zephir_array_update_string(&_6, SL("$lte"), &minAgeMongo, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&query, SL("modified"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&remove, _7, "remove", NULL, query);
	zephir_check_call_status();
	_8 = zephir_array_isset_string(remove, SS("ok"));
	if (_8) {
		ZEPHIR_OBS_VAR(_9);
		zephir_array_fetch_string(&_9, remove, SL("ok"), PH_NOISY TSRMLS_CC);
		_8 = zephir_get_boolval(_9);
	}
	RETURN_MM_BOOL(_8);

}

