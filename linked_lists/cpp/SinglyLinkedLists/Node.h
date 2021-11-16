#pragma once

#include <iostream>

class Node {
public:
  Node(int value = 0);
  ~Node();

  bool operator==(const Node &rhs) const;

  // print the node value
  void print();
  // print the list starting at this node
  void printList(const char *sep = ", ");

  // appends value to the tail of this node
  Node *append(int value);
  // append n nodes to this node, starting with value
  Node *append_n(int value, size_t n);
  // insert value after the node with after_value
  Node *insert_after(int value, int after_value);
  // insert value before the node with before_value
  Node *insert_before(int value, int before_value, Node *prev = nullptr);
  // Remove the node represented by value. A node cannot remove itself without a valid prev pointer.
  Node *remove(int value, Node *prev = nullptr);
  // return whether or not value is in the list
  bool exists(int value);
  // get the node with value
  Node *get(int value);
  // return the next node in the list
  Node *next() const;
  // set the next node in the list
  void setNext(Node *node);

  // get the last node
  Node *tail();
  // get the node value
  int value() const;
  // Delete all nodes after this node.
  // The "trim" flag indicates whether or not to delete this node.
  // By default "trim" is false (preserving the calling node).
  void trim(bool trim = false);

protected:
  // a dumb appender. Only call when guaranteed appending to the tail.
  Node *append_strict(int value);

  Node *_next;
  int _value;

}; // class Node
