#include "Reverser.h"

static void swap(SingleNode *&a, SingleNode *&b) {
  SingleNode *tmp = a;
  a = b;
  b = tmp;
}

//Reverser::~Reverser() {
//  // free memory for all nodes following the head
//  _head->trim();
//  // free memory for the head
//  delete _head;
//  _head = nullptr;
//}

// before: (head)a->b->c->d(tail)
// after:  (head)a<->b<-c<-d(tail)
//
// 3. a,b (a<->b) : a still points to b. It needs to be (null<-a<-b)
// 2.   b,c (b<-c)
// 1.     c,d (c<-d)
// Because of the recursive nature of this function, there is no way to
// update the head's _next ptr to null (null<-a). This leaves us in a final
// state of a<->b that we correct after we fully return from this function.
void Reverser::reverse_1(SingleNode *curr, SingleNode *next) {
  if (next->next()) {
    // follow the linked list to the end
    reverse_1(next, next->next());
  }
  // reverse ptr assignments are made as the recursion unwinds
  next->setNext(curr);
}

// Perform the in-place reversal
void Reverser::exec_1(SingleNode *&head) {
  // 1. Reversal of each link happens with 2 pointers (current, and next).
  // 2. Must manually set the old head's _next ptr to null.
  // 3. Requires a tail node to swap with the head as last step.
  SingleNode *tail = head->tail();

  if (head->next()) {
    // head->next : head<->next
    reverse_1(head, head->next());
    // null<-head<-next
    head->setNext(nullptr);
    // swap the head and tail
    // std::swap(head, tail);
    swap(head, tail);
  }
}
