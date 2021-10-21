#include "Node.h"

// Two drawbacks to this method:
// 1. Requires a tail node to swap with the head as last step.
// 2. Must manually set the old head's _next ptr to null.
class ReverseList_1 {
public:
  // before: (head)a->b->c->d(tail)
  // after:  (tail)d->c->b->a(head)
  // a,b (b->a)
  //   b,c (c->b)
  //     c,d (d->c)
  // NOTE: Because of the recursive nature of this function, there is no way to
  // know to update the head's _next ptr to null. This leaves us in a final
  // state of a<->b.
  void reverse(Node *a, Node *b) {
    if (b->_next) {
      // follow the linked list to the end
      reverse(b, b->_next);
    }
    // reverse ptr assignments are made as the recursion unwinds
    b->_next = a;
  }

  void run() {
    // node values begin with 1
    int value = 1;
    // create the head node
    Node *head = new Node(value);
    // append 9 more nodes to the head starting with the next value
    Node *tail = makeList(head, 9, ++value);
    // separator string for printing
    const char *sep = ", ";

    // before
    cout << "before:\t";
    head->printList(sep);

    // Perform the in-place reversal
    {
      if (head->_next) {
        reverse(head, head->_next);
        // update the head here (now at the end)
        head->_next = nullptr;
      }
      // update the head to the tail
      head = tail;
    }

    // after
    cout << "after:\t";
    head->printList(sep);
    // cleanup
    head->deleteList();
  }
};