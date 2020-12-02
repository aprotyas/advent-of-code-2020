#pragma once
#include <password/password.h>
#include <passwordpolicy/passwordpolicy.h>

#include <fstream>
#include <iostream>
#include <string>

namespace day_02 {
namespace part1 {
bool is_valid(const Password &pw);
}

namespace part2 {
std::vector<Password> read_file(std::string fname);
}
std::vector<Password> read_file(std::string fname);
uint32_t part_one(std::vector<Password> input);
uint32_t part_two(std::vector<Password> input);
std::ostream &operator<<(std::ostream &os,
                         const std::vector<Password> &passwords);
} // namespace day_02
