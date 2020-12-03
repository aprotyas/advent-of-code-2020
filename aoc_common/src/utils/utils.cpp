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
} // namespace utils
