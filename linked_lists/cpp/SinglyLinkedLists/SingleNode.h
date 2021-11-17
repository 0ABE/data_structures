#pragma once

#include <iostream>

#include "../AbstractNode.h"

class SingleNode : AbstractNode {
public:
  SingleNode(int value = 0);
  ~SingleNode();

  bool operator==(SingleNode &rhs);

  // appends value to the tail of this node
  virtual SingleNode *append(int value, enum DIRECTION dx = NEXT);

  // append n nodes to this node, starting with value
  virtual SingleNode *append_n(int value, size_t n, enum DIRECTION dx = NEXT);

  // return whether or not value is in the list
  bool exists(int value);

  // get the node with value
  virtual SingleNode *get(int value, enum DIRECTION dx = NEXT);

  // insert value after the node with after_value
  virtual SingleNode *insert_after(int value, int after_value,
                                   enum DIRECTION dx = NEXT);

  // insert value before the node with before_value
  virtual SingleNode *insert_before(int value, int before_value,
                                    SingleNode *prev = nullptr,
                                    enum DIRECTION dx = NEXT);

  // print the list starting at this node
  virtual void printList(const char *sep = ", ", enum DIRECTION dx = NEXT) const;

  // Remove the node represented by value.
  // A node cannot remove itself without a valid prev pointer.
  virtual SingleNode *remove(int value, SingleNode *prev = nullptr,
                             enum DIRECTION dx = NEXT);

  // return the next node in the list
  virtual SingleNode *step(enum DIRECTION dx = NEXT);

  // set the next node in the list
  void setNext(SingleNode *node);

  // get the last node
  SingleNode *tail();

  // Delete all nodes after this node.
  // The "trim" flag indicates whether or not to delete this node.
  // By default "trim" is false (preserving the calling node).
  virtual void trim(bool trim = false, enum DIRECTION dx = NEXT);

protected:
  // a dumb appender. Only call when guaranteed appending to an end.
  virtual SingleNode *append_strict(int value, enum DIRECTION dx = NEXT);

  SingleNode *_next;

}; // class SingleNode
