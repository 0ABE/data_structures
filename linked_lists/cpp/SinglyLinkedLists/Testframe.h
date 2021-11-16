#pragma once

#include "assert.h"
#include <vector>

#include "ListBuilder.h"
#include "Node.h"
#include "Reverser.h"

class Testframe {
public:
  static bool test_equals(Node *lhs, Node *rhs);
  static bool test_exists(Node *node, int value);
  static bool test_missing(Node *node, int value);

  void exec();
};