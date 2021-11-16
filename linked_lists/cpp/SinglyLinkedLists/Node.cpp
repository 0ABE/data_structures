#include "Node.h"

Node::Node(int value) : _value(value), _next(nullptr) {}

Node::~Node() {
  // free memory for all nodes following this node
  if (_next) {
    delete _next;
  }
}

bool Node::operator==(const Node &rhs) const {
  if (value() == rhs.value()) {
    if (next() && rhs.next()) {
      return (*next() == *rhs.next());
    } else {
      return true;
    }
  } else {
    return false;
  }
}

Node *Node::next() const { return _next; }

void Node::setNext(Node *node) { _next = node; }

int Node::value() const { return _value; }

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
  if (_next) {
    // first find the tail, then append
    return _next->append(value);
  } else {
    return append_strict(value);
  }
}

Node *Node::append_strict(int value) {
  // append the new value to this node
  _next = new Node(value);
  return _next;
}

Node *Node::append_n(int value, size_t n) {
  if (n < 1) {
    return nullptr;
  } else if (n == 1) {
    return append_strict(value);
  } else {
    Node *next = append_strict(value);
    return next->append_n(++value, --n);
  }
}

Node *Node::insert_after(int value, int after_value) {
  if (_value == after_value) {
    Node *old_next = nullptr;
    if (_next) {
      // keep a handle on the rest of the list
      old_next = _next;
      // this potentially breaks the list when we insert the new value
      Node *appended = append_strict(value);
      // if there was more to the list, reconnect it
      if (old_next) {
        appended->setNext(old_next);
      }
      return appended;
    } else {
      // attempting to insert at the end of the list
      // just append the new value
      return append_strict(value);
    }
  } else {
    // this wasn't the node, try next
    if (_next) {
      return _next->insert_after(value, after_value);
    } else {
      // after_value not found, value not inserted
      return nullptr;
    }
  }
}

Node *Node::insert_before(int value, int before_value, Node *prev) {
  if (_value == before_value) {
    // make the node to insert
    Node *node = new Node(value);
    // before: prev->this
    // after:  prev->node->this
    // make new links to node
    // set node->this
    node->setNext(this);
    // if there is a previous node, link it to the newly inserted one
    // set prev->node
    if (prev) {
      prev->setNext(node);
    }
    return node;
  } else {
    if (_next) {
      // if there's a next node, try that one
      // this node is the next previous node
      return _next->insert_before(value, before_value, this);
    } else {
      // before_value not found, value wasn't inserted
      return nullptr;
    }
  }
}

Node *Node::remove(int value, Node *prev) {
  if (prev && value == _value) {
    if (prev) {
      // set the previous node to the next node
      // which has the effect of skipping this node
      prev->setNext(_next);
      // remove this node's link to the next node
      _next = nullptr;
      return this;
    }
  }
  // this node didn't hold the value, try the next node
  if (_next) {
    // this node is the next previous node
    return _next->remove(value, this);
  } else {
    // no more nodes and the value wasn't found to remove
    return nullptr;
  }
}

bool Node::exists(int value) {
  Node *node = get(value);
  return (node != nullptr);
}

Node *Node::get(int value) {
  if (_value == value) {
    return this;
  } else {
    if (_next) {
      return _next->get(value);
    } else {
      return nullptr;
    }
  }
}

Node *Node::tail() {
  if (_next) {
    return _next->tail();
  }
  return this;
}

void Node::trim(bool trim) {
  if (_next) {
    // seek to the end of the list, with trim set to true
    _next->trim(true);
    // The end is found. Reset _next to
    // no longer point to the next node.
    _next = nullptr;
  }
  if (trim) {
    // trim is true so delete this node
    delete this;
  }
}
