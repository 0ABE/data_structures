#include "Testframe.h"

bool Testframe::test_equals(SingleNode *lhs, SingleNode *rhs) {
  if (!lhs && !rhs) {
    // true if both nodes are null
    return true;
  } else {
    // compare equality of nodes
    assert(*lhs == *rhs);
  }
  if (rhs) {
    // rhs is used only temporarily for comparison. free it now.
    delete rhs;
  }
  return true;
}

bool Testframe::test_exists(SingleNode *node, int value) {
  assert(node->exists(value));
  return true;
}

bool Testframe::test_missing(SingleNode *node, int value) {
  assert(!node->exists(value));
  return true;
}

void Testframe::exec() {
  Reverser reverser;
  ListBuilder listBuilder;

  SingleNode *list = listBuilder.build(1, 5);

  // print the list as created
  list->printList();

  // test listBuilder
  test_equals(list, listBuilder.build({1, 2, 3, 4, 5}));

  // test insert_after
  list->insert_after(10, 1);
  test_equals(list, listBuilder.build({1, 10, 2, 3, 4, 5}));

  // test insert_before
  list->insert_before(20, 3); // before a value that exists
  list->insert_before(20, 0); // before a missing value
  test_equals(list, listBuilder.build({1, 10, 2, 20, 3, 4, 5}));

  // append 30 to 3
  SingleNode *node_3 = list->get(3);
  node_3->append(30);
  test_equals(list, listBuilder.build({1, 10, 2, 20, 3, 4, 5, 30}));
  test_equals(node_3, listBuilder.build({3, 4, 5, 30}));

  // append 50 to list head
  list->append(50);
  test_equals(list, listBuilder.build({1, 10, 2, 20, 3, 4, 5, 30, 50}));

  // does 30 exist?
  test_exists(list, 30);

  // remove 30
  if (SingleNode *node_30 = list->remove(30)) {
    // node_30 has no next nodes
    test_equals(node_30, listBuilder.build({30}));
    // free the memory
    delete node_30;
  }
  test_equals(list, listBuilder.build({1, 10, 2, 20, 3, 4, 5, 50}));
  test_equals(node_3, listBuilder.build({3, 4, 5}));

  // 30 should no longer exist
  test_missing(list, 30);

  // trim the list after the 4
  SingleNode *node_4 = list->get(4);
  node_4->trim();
  test_equals(list, listBuilder.build({1, 10, 2, 20, 3, 4}));
  test_equals(node_3, listBuilder.build({3, 4}));
  test_equals(node_4, listBuilder.build({4}));

  // remove an existing value from the end
  // node node_4 can remove itself only with a previous node (node_3 in this
  // case)
  if (SingleNode *node_4b = node_4->remove(4, node_3)) {
    // node_4b has no next nodes
    test_equals(node_4b, listBuilder.build({4}));
    // ree the memory
    delete node_4b;
  }
  test_equals(list, listBuilder.build({1, 10, 2, 20, 3}));
  test_equals(node_3, listBuilder.build({3}));

  // reverse the list
  reverser.exec_1(list);
  test_equals(list, listBuilder.build({3, 20, 2, 10, 1}));

  // remove an existing value from the middle
  if (SingleNode *node_2 = list->remove(2)) {
    // node_2 has no next nodes
    test_equals(node_2, listBuilder.build({2}));
    // free the memory
    delete node_2;
  }
  test_equals(list, listBuilder.build({3, 20, 10, 1}));

  // removing a non-existant value does nothing
  SingleNode *node_2 = list->remove(2);
  // node_2 should be null since 2 couldn't be found
  test_equals(nullptr, node_2);
  test_equals(list, listBuilder.build({3, 20, 10, 1}));

  // 5 can't be inserted because 4 doesn't exist
  list->insert_before(5, 4);
  test_equals(list, listBuilder.build({3, 20, 10, 1}));

  // do some more operations
  list->remove(10);
  list->remove(20);
  // inserting at the beginning so reset our head pointer
  list = list->insert_before(4, 3);
  list = list->insert_before(5, 4);
  list->insert_after(2, 3);
  list->append(0);
  list->append(0);
  test_equals(list, listBuilder.build({5, 4, 3, 2, 1, 0, 0}));

  // remove the 2 nodes with value 0, but try removing more than 2 times
  for (int i = 0; i < 5; i++) {
    if (SingleNode *node_0 = list->remove(0)) {
      delete node_0;
    }
  }

  reverser.exec_1(list);
  test_equals(list, listBuilder.build({1, 2, 3, 4, 5}));

  list->printList();

  // free memory
  delete list;
}