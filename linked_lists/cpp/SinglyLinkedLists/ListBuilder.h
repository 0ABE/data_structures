#pragma once

#include <vector>
#include "Node.h"

class ListBuilder {
public:
	Node* build(int init_value, size_t list_size);
	Node* build(const std::vector<int> &values);
};