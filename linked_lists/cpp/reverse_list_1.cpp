#pragma once
#include "includes.h"

// using namespace SinglyLinkedList;
using namespace std;

static void swap(Node *&a, Node *&b) {
  Node *tmp = a;
  a = b;
  b = tmp;
}

// Notes:
// 1. Reversal happens with only 2 pointers (current, and next)
// 2. Requires a tail node to swap with the head as last step.
// 3. Must manually set the old head's _next ptr to null.
class ReverseList_1 {
public:
  // before: (head)a->b->c->d(tail)
  // after:  (head)a<->b<-c<-d(tail)
  // 3. a,b (a<->b) : a still points to b. It needs to be (null<-a<-b)
  // 2.   b,c (b<-c)
  // 1.     c,d (c<-d)
  // Because of the recursive nature of this function, there is no way to
  // update the head's _next ptr to null (null<-a). This leaves us in a final
  // state of a<->b that we correct after we fully return from this function.
  void reverse(Node *curr, Node *next) {
    if (next->next()) {
      // follow the linked list to the end
      reverse(next, next->next());
    }
    // reverse ptr assignments are made as the recursion unwinds
    next->setNext(curr);
  }

  void run() {
    // first value in the list
    int value = 1;
    // how many nodes in the list
    int listSize = 20;
    // create the head node
    Node *head = new Node(value);
    // append 9 more nodes to the head starting with the next value
    Node *tail = head->append(++value, listSize - 1);

    // before reversing
    cout << "before:\t";
    head->printList();

    // Perform the in-place reversal
    {
      if (head->next()) {
        // head->next : head<->next
        reverse(head, head->next());
        // null<-head<-next
        head->setNext(nullptr);
        // swap the head and tail
        // std::swap(head, tail);
        swap(head, tail);
      }
    }

    // after reversing
    cout << "after:\t";
    head->printList();

    // cleanup
    head->trim();
    delete head;
    head = nullptr;
  }
};