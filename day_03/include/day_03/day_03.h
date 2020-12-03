#pragma once

#include <world/world.h>

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

namespace day_03 {
World parse_input(const std::vector<std::string> &input);
uint32_t part_one(const World &world,
                  const std::pair<uint32_t, uint32_t> &step = {1, 3});
uint32_t part_two(const World &world);
} // namespace day_03
