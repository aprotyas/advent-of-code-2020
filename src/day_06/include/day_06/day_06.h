#pragma once
#include <group/group.h>
#include <iostream>
#include <string>
#include <vector>

namespace day_06 {
std::vector<Group> parse_groups(std::vector<std::string> ans);
uint32_t part_one(const std::vector<Group> &in);
uint32_t part_two(const std::vector<Group> &in);
} // namespace day_06
