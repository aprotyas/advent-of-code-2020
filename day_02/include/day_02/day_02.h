#pragma once
#include <password/password.h>
#include <passwordpolicy/passwordpolicy.h>

#include <fstream>
#include <iostream>
#include <string>

namespace day_02 {

/*
 *  Separate validity conditions for part1 and part2,
 *  hence is_valid() put into two distinct namespaces
 */

namespace part1 {
bool is_valid(const Password &pw);
}

namespace part2 {
bool is_valid(const Password &pw);
}

uint32_t part_one(std::vector<Password> input);
uint32_t part_two(std::vector<Password> input);

/*
 *  read_file() and ostream operator overloading common
 *  for both parts
 */

std::vector<Password> read_file(std::string fname);
std::ostream &operator<<(std::ostream &os,
                         const std::vector<Password> &passwords);
} // namespace day_02
