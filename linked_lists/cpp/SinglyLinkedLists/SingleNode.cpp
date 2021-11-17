#include "SingleNode.h"

SingleNode::SingleNode(int value) : _value(value), _next(nullptr) {}

SingleNode::~SingleNode() {
  // free memory for all nodes following this one
  if (_next) {
    delete _next;
  }
}

bool SingleNode::operator==(const SingleNode &rhs) const {
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

SingleNode *SingleNode::next() const { return _next; }

void SingleNode::setNext(SingleNode *node) { _next = node; }

int SingleNode::value() const { return _value; }

void SingleNode::print() { std::cout << _value; }

void SingleNode::printList(const char *sep) {
  print();
  if (_next) {
    std::cout << sep;
    _next->printList(sep);
  } else {
    std::cout << '\n';
  }
}

SingleNode *SingleNode::append(int value) {
  if (_next) {
    // first find the tail, then append
    return _next->append(value);
  } else {
    return append_strict(value);
  }
}

SingleNode *SingleNode::append_strict(int value) {
  // append the new value to this node
  _next = new SingleNode(value);
  return _next;
}

SingleNode *SingleNode::append_n(int value, size_t n) {
  if (n < 1) {
    return nullptr;
  } else if (n == 1) {
    return append_strict(value);
  } else {
    SingleNode *next = append_strict(value);
    return next->append_n(++value, --n);
  }
}

SingleNode *SingleNode::insert_after(int value, int after_value) {
  if (_value == after_value) {
    SingleNode *old_next = nullptr;
    if (_next) {
      // keep a handle on the rest of the list
      old_next = _next;
      // this potentially breaks the list when we insert the new value
      SingleNode *appended = append_strict(value);
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

SingleNode *SingleNode::insert_before(int value, int before_value, SingleNode *prev) {
  if (_value == before_value) {
    // make the node to insert
    SingleNode *node = new SingleNode(value);
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

SingleNode *SingleNode::remove(int value, SingleNode *prev) {
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

bool SingleNode::exists(int value) {
  SingleNode *node = get(value);
  return (node != nullptr);
}

SingleNode *SingleNode::get(int value) {
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

SingleNode *SingleNode::tail() {
  if (_next) {
    return _next->tail();
  }
  return this;
}

void SingleNode::trim(bool trim) {
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
