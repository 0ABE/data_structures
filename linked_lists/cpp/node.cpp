#pragma once
#include "includes.h"

using namespace std;

Node::Node(int value = 0) : _value(value), _next(nullptr) {}

Node *Node::next() { return _next; }

void Node::setNext(Node *node) { _next = node; }

int Node::value() { return _value; }

void Node::print() { cout << _value; }

void Node::printList(const char *sep) {
  print();
  if (_next) {
    cout << sep;
    _next->printList(sep);
  } else {
    cout << endl;
  }
}

Node *Node::append(int value) {
  _next = new Node(value);
  return _next;
}

Node *Node::append(int value, size_t count) {
  if (count < 1)
    return nullptr;
  if (count == 1)
    return append(value);
  else
    return append(value)->append(++value, --count);
}

Node *Node::tail() {
  if (_next) {
    return _next->tail();
  }
  return this;
}

void Node::trim() {
  if (_next) {
    _next->trim();
  }
  // delete as we unwind from the end
  if (_next)
    delete _next;
}
