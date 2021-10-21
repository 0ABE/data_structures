#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
public:
  Node(int value = 0) : _value(value), _next(nullptr) {}

  void printNode() { cout << _value; }

  void printList(const char *sep = " ") {
    printNode();
    if (_next) {
      cout << sep;
      _next->printList(sep);
    } else {
      cout << endl;
    }
  }

  Node *append(int value) {
    _next = new Node(value);
    return _next;
  }

  Node *tail() {
    if (_next) {
      return _next->tail();
    }
    return this;
  }

  void deleteList() {
    if (_next) {
      _next->deleteList();
    }
    delete this;
  }

  Node *_next;
  int _value;
}; // class Node

static Node *makeList(Node *node, size_t size, int value) {
  if (size < 1)
    return nullptr;
  if (size == 1)
    return node->append(value);
  else
    return makeList(node->append(value++), --size, value);
}

#endif // NODE_H