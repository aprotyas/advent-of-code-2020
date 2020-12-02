#pragma once
#include <iterator>
#include <fstream>
#include <cstdint>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

namespace day_01
{
    uint32_t part_one(std::vector<uint32_t> input, uint32_t target = 2020);
    uint32_t part_two(std::vector<uint32_t> input, uint32_t target = 2020);
    std::vector<uint32_t> read_file(std::string fname);
    std::ostream& operator<<(std::ostream& os, const std::vector<uint32_t>& file);
}
