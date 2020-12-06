#pragma once
#include <passport/passport.h>

#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace day_04 {
std::vector<Passport> parse_input(const std::vector<std::string> &in);
uint32_t part_one(std::vector<Passport> &in);
uint32_t part_two(std::vector<Passport> &in);

namespace part_01 {
bool is_valid(Passport &pass);
} // namespace part_01

namespace part_02 {
bool is_valid(Passport &pass);
} // namespace part_02
} // namespace day_04
