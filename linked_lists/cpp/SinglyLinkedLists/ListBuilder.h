#pragma once

#include <vector>
#include "SingleNode.h"

class ListBuilder {
public:
	SingleNode* build(int init_value, size_t list_size);
	SingleNode* build(const std::vector<int> &values);
};