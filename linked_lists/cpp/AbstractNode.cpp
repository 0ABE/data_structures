#include "AbstractNode.h"

AbstractNode::AbstractNode(int value) : _value(value) {}

AbstractNode::AbstractNode(const AbstractNode& rhs) {
  _value = rhs.value();
}

bool AbstractNode::operator==(const AbstractNode &rhs) const {
  return (_value == rhs.value());
}

int AbstractNode::value() const { return _value; }

void AbstractNode::print() const { std::cout << _value; }
