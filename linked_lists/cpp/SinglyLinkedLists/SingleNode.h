#pragma once

#include <iostream>

class SingleNode {
public:
  SingleNode(int value = 0);
  ~SingleNode();

  bool operator==(const SingleNode &rhs) const;

  // print the node value
  void print();
  // print the list starting at this node
  void printList(const char *sep = ", ");

  // appends value to the tail of this node
  SingleNode *append(int value);
  // append n nodes to this node, starting with value
  SingleNode *append_n(int value, size_t n);
  // insert value after the node with after_value
  SingleNode *insert_after(int value, int after_value);
  // insert value before the node with before_value
  SingleNode *insert_before(int value, int before_value, SingleNode *prev = nullptr);
  // Remove the node represented by value. A node cannot remove itself without a valid prev pointer.
  SingleNode *remove(int value, SingleNode *prev = nullptr);
  // return whether or not value is in the list
  bool exists(int value);
  // get the node with value
  SingleNode *get(int value);
  // return the next node in the list
  SingleNode *next() const;
  // set the next node in the list
  void setNext(SingleNode *node);

  // get the last node
  SingleNode *tail();
  // get the node value
  int value() const;
  // Delete all nodes after this node.
  // The "trim" flag indicates whether or not to delete this node.
  // By default "trim" is false (preserving the calling node).
  void trim(bool trim = false);

protected:
  // a dumb appender. Only call when guaranteed appending to the tail.
  SingleNode *append_strict(int value);

  SingleNode *_next;
  int _value;

}; // class SingleNode
