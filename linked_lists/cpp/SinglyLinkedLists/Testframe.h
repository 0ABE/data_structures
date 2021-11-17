#pragma once

#include "assert.h"
#include <vector>

#include "ListBuilder.h"
#include "SingleNode.h"
#include "Reverser.h"

class Testframe {
public:
  static bool test_equals(SingleNode *lhs, SingleNode *rhs);
  static bool test_exists(SingleNode *node, int value);
  static bool test_missing(SingleNode *node, int value);

  void exec();
};