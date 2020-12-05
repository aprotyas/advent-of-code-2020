#pragma once
#include <fstream>
#include <string>
#include <vector>

namespace utils {
std::vector<std::string> read_file(std::string fname);
uint32_t bin2dec(std::string code, char zero = '0', char one = '1');
} // namespace utils
