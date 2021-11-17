#pragma once

#include <iostream>

// which direction to print the doubly linked list
enum DIRECTION { NEXT, PREV };

class AbstractNode {
public:
  AbstractNode(int value = 0);
  AbstractNode(const AbstractNode &rhs);
  ~AbstractNode() = default;

  virtual bool operator==(const AbstractNode &rhs) const;

  // print the node value
  void print() const;

  // get the node value
  int value() const;

protected:
  int _value;

}; // class AbstractNode
