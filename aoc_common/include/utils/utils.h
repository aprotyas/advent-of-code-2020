#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

namespace utils
{
    std::vector<uint32_t> read_file(std::string fname);
}

std::ostream& operator<<(std::ostream& os, const std::vector<uint32_t>& file);
