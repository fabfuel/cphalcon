
extern zend_class_entry *phalcon_session_adapter_mongodb_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_MongoDB);

PHP_METHOD(Phalcon_Session_Adapter_MongoDB, getData);
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, getUser);
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, setUser);
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, getCollection);
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, __construct);
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, open);
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, close);
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, read);
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, save);
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, destroy);
PHP_METHOD(Phalcon_Session_Adapter_MongoDB, gc);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_mongodb_setuser, 0, 0, 1)
	ZEND_ARG_INFO(0, user)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_mongodb___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_mongodb_read, 0, 0, 1)
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_mongodb_save, 0, 0, 0)
	ZEND_ARG_INFO(0, sessionId)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_mongodb_destroy, 0, 0, 0)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_mongodb_gc, 0, 0, 0)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapter_mongodb_method_entry) {
	PHP_ME(Phalcon_Session_Adapter_MongoDB, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_MongoDB, getUser, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_MongoDB, setUser, arginfo_phalcon_session_adapter_mongodb_setuser, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_MongoDB, getCollection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_MongoDB, __construct, arginfo_phalcon_session_adapter_mongodb___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Adapter_MongoDB, open, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_MongoDB, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_MongoDB, read, arginfo_phalcon_session_adapter_mongodb_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_MongoDB, save, arginfo_phalcon_session_adapter_mongodb_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_MongoDB, destroy, arginfo_phalcon_session_adapter_mongodb_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_MongoDB, gc, arginfo_phalcon_session_adapter_mongodb_gc, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
