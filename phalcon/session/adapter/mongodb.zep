
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

namespace Phalcon\Session\Adapter;

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
class MongoDB extends \Phalcon\Session\Adapter implements \Phalcon\Session\AdapterInterface
{
    /**
     * Current session data
     *
     * @var string
     */
	protected _data = NULL { get };

    /**
     * @var \MongoId
     */
	protected _user = NULL { get, set };

    /**
     * @var \MongoCollection
     */
	protected _collection = NULL { get };

	/**
	 * Phalcon\Session\Adapter\MongoDB constructor
	 *
	 * @param array options
	 */
	public function __construct(options = null)
	{
	    if typeof options != "array" {
			throw new \Phalcon\Session\Exception("Options must be an Array");
		}

		if !isset options["collection"] {
			throw new \Phalcon\Session\Exception("The parameter 'collection' is required and has to be an instance of \\MongoCollection");
		}

		let this->_collection = options["collection"];


		session_set_save_handler(
			[this, "open"],
			[this, "close"],
			[this, "read"],
			[this, "save"],
			[this, "destroy"],
			[this, "gc"]
		);

		parent::__construct(options);
	}

    /**
     * @return bool
     */
	public function open()
	{
		return true;
	}

    /**
     * @return bool
     */
	public function close()
	{
		return true;
	}

	/**
	 * {@inheritdoc}
	 *
	 * @param string sessionId
	 * @return mixed
	 */
    public function read(sessionId)
    {
        var sessionData;

        let sessionData = this->getCollection()->findOne(["_id" : sessionId]);

        if (isset(sessionData["user"])) {
            this->setUser(sessionData["user"]);
        }

        if (isset(sessionData["data"])) {
            let this->_data = sessionData["data"];
            return this->_data;
        }

        return "";
    }

    /**
     * {@inheritdoc}
     *
     * @param mixed sessionId
     * @param mixed data
     */
    public function save(sessionId = null, data = "")
    {
        array document = ["_id" : "foobar"];

        this->getCollection()->save(document);
//        var_dump(document);

//        let document["_id"] = "foobar";

        return true;

    }

    /**
     * {@inheritdoc}
     *
     * @param  string  session_id
     * @return boolean
     */
    public function destroy(session_id = null)
    {
        var remove;

        if (session_id === null) {
            let session_id = session_id();
        }

        let this->_data = null;

        let remove = this->getCollection()->remove(["_id" : session_id]);

        return isset(remove["ok"]) && (bool)remove["ok"];
    }

    /**
     * {@inheritdoc}
     */
    public function gc(lifetime = 86400)
    {
        var minAge,
            minAgeMongo,
            query,
            remove;

        let minAge = new \DateTime();
        minAge->sub(new \DateInterval("PT" . lifetime . "S"));

        let minAgeMongo = new \MongoDate(minAge->getTimestamp());
        let query = ["modified" : ["$lte" : minAgeMongo]];
        let remove = this->getCollection()->remove(query);

        return isset(remove["ok"]) && (bool)remove["ok"];
    }
}
