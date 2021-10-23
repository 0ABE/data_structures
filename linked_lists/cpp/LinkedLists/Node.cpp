#include "Node.h"

Node::Node(int value = 0) : _value(value), _next(nullptr) {}

Node::~Node() {
  // free memory for all nodes following this node
    if (_next) {
        delete _next;
    }
}

Node *Node::next() { return _next; }

void Node::setNext(Node *node) { _next = node; }

int Node::value() { return _value; }

void Node::print() { std::cout << _value; }

void Node::printList(const char *sep) {
  print();
  if (_next) {
    std::cout << sep;
    _next->printList(sep);
  } else {
    std::cout << '\n';
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
  else {
    Node *next = append(value);
    return next->append(++value, --count);
  }
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
