Run w/o async spinner:
======================

Run:

``` bash
$ rosrun test_async_spinner test_no_async_spinner_node
```

and you'll see an output like this, showing that the slow callback blocks the fast one:

``` bash
[ INFO] [/test_no_async_spinner_node] [1500313516.890924585]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
[ INFO] [/test_no_async_spinner_node] [1500313517.890756108]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
[ INFO] [/test_no_async_spinner_node] [1500313518.890440569]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
[ INFO] [/test_no_async_spinner_node] [1500313519.311835085]: void Node::heavyCallback(const Int32ConstPtr&) received message data: 100000000
[ INFO] [/test_no_async_spinner_node] [1500313525.512592864]: void Node::heavyCallback(const Int32ConstPtr&) DONE (sum = 2.5e+31)
[ INFO] [/test_no_async_spinner_node] [1500313525.512651005]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
[ INFO] [/test_no_async_spinner_node] [1500313525.890475353]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
[ INFO] [/test_no_async_spinner_node] [1500313526.890443314]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
```

Run w/ async spinner:
=====================

Run:

``` bash
$ rosrun test_async_spinner test_async_spinner_node
```

and you'll see an output like this, showing that the slow callback doesn't block the fast one:

``` bash
[ INFO] [/test_async_spinner_node] [1500313815.891051813]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
[ INFO] [/test_async_spinner_node] [1500313816.890726691]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
[ INFO] [/test_async_spinner_node] [1500313817.890810149]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
[ INFO] [/test_async_spinner_node] [1500313818.772134942]: void Node::heavyCallback(const Int32ConstPtr&) received message data: 100000000
[ INFO] [/test_async_spinner_node] [1500313818.890455311]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
[ INFO] [/test_async_spinner_node] [1500313819.890355748]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
[ INFO] [/test_async_spinner_node] [1500313820.890352268]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
[ INFO] [/test_async_spinner_node] [1500313821.890377772]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
[ INFO] [/test_async_spinner_node] [1500313822.890384840]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
[ INFO] [/test_async_spinner_node] [1500313823.890389861]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
[ INFO] [/test_async_spinner_node] [1500313824.890107593]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
[ INFO] [/test_async_spinner_node] [1500313825.016150514]: void Node::heavyCallback(const Int32ConstPtr&) DONE (sum = 2.5e+31)
[ INFO] [/test_async_spinner_node] [1500313825.890644178]: void Node::lightCallback(const Int32ConstPtr&) received message data: 3
```
