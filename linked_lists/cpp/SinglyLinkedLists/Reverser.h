#pragma once

#include "SingleNode.h"

class Reverser {
public:
  void exec_1(SingleNode *&head);

protected:
  // Notes:
  // 1. Reversal happens with only 2 pointers (current, and next)
  // 2. Requires a tail node to swap with the head as last step.
  // 3. Must manually set the old head's _next ptr to null.
  void reverse_1(SingleNode *curr, SingleNode *next);

}; // class Reverse
