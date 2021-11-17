#include "ListBuilder.h"

SingleNode *ListBuilder::build(int init_value, size_t list_size) {
  // create the head node
  SingleNode *head = new SingleNode(init_value);

  // append more nodes to the head starting with the next value
  head->append_n(++init_value, list_size - 1);

  return head;
}

SingleNode *ListBuilder::build(const std::vector<int> &values) {
  int n = values.size();
  SingleNode *head = nullptr;
  if (n > 0) {
    head = new SingleNode(values[0]);
    for (int i = 1; i < n; i++) {
      head->append(values[i]);
    }
  }

  return head;
}
