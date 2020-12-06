#include <utils/utils.h>

namespace utils {
std::vector<std::string> read_file(std::string fname) {
    std::string line{};
    std::vector<std::string> lines{};
    std::ifstream ifs(fname);
    while (std::getline(ifs, line)) {
        lines.push_back(line);
    }
    return lines;
}

uint32_t bin2dec(std::string code, char zero, char one) {
    uint32_t dec{0}, pos{0};
    for (auto it{code.crbegin()}; it != code.crend(); it++, pos++) {
        if (*it == one) {
            dec += 1 << pos;
        }
    }
    return dec;
}
} // namespace utils
