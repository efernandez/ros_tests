Run w/o async spinner:
======================

Run:

$ rosrun test_async_spinner test_no_async_spinner_node

and you'll see an output like this, showing that the slow callback blocks the fast one:



Run w/ asyn spinner:
====================

Run:

$ rosrun test_async_spinner test_async_spinner_node

and you'll see an output like this, showing that the slow callback doesn't block the fast one:


