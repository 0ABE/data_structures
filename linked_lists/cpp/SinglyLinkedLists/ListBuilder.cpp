#include "ListBuilder.h"

Node *ListBuilder::build(int init_value, size_t list_size) {
  // create the head node
  Node *head = new Node(init_value);

  // append more nodes to the head starting with the next value
  head->append_n(++init_value, list_size - 1);

  return head;
}

Node *ListBuilder::build(const std::vector<int> &values) {
  int n = values.size();
  Node *head = nullptr;
  if (n > 0) {
    head = new Node(values[0]);
    for (int i = 1; i < n; i++) {
      head->append(values[i]);
    }
  }

  return head;
}
