#include <day_02/day_02.h>

namespace day_02 {
namespace part1 {
bool is_valid(const Password &pw) {
    std::string pass{pw.get_password()};
    PasswordPolicy policy{pw.get_policy()};
    std::uint32_t count{static_cast<uint32_t>(
        std::count(pass.begin(), pass.end(), policy.get_policy_letter()))};
    return count >= policy.get_policy_a() && count <= policy.get_policy_b();
}
} // namespace part1

namespace part2 {
bool is_valid(const Password &pw) {
    std::string pass{pw.get_password()};
    PasswordPolicy policy{pw.get_policy()};
    uint32_t l_idx{policy.get_policy_a() - 1};
    uint32_t r_idx{policy.get_policy_b() - 1};
    char c{policy.get_policy_letter()};
    return (pass[l_idx] == c) != (pass[r_idx] == c);
}
} // namespace part2

uint32_t part_one(std::vector<Password> input) {
    uint32_t valid{0};
    for (const auto &pw : input) {
        valid += static_cast<uint32_t>(part1::is_valid(pw));
    }
    return valid;
}

uint32_t part_two(std::vector<Password> input) {
    uint32_t valid{0};
    for (const auto &pw : input) {
        valid += static_cast<uint32_t>(part2::is_valid(pw));
    }
    return valid;
}

std::vector<Password> read_file(std::string fname) {
    std::string line{};
    std::vector<Password> buffer{};
    std::ifstream ifs(fname);
    int line_num{1};
    while (std::getline(ifs, line)) {
        uint32_t a{};
        uint32_t b{};
        uint32_t num_delim_pos{};
        char policy_letter{};
        std::string password{};
        for (uint32_t idx{0}; idx < line.size(); idx++) {
            if (line[idx] == '-') {
                num_delim_pos = idx;
                // reached the number delimiter
                a = std::stoi(line.substr(0, num_delim_pos));
            }
            if (line[idx] == ' ') {
                b = std::stoi(
                    line.substr(num_delim_pos + 1, idx - num_delim_pos - 1));
                policy_letter = line[idx + 1];
                password = line.substr(idx + 4, line.size());
                break;
            }
        }
        buffer.push_back({password, {policy_letter, a, b}});
    }
    return buffer;
}

std::ostream &operator<<(std::ostream &os,
                         const std::vector<Password> &passwords) {
    return os;
}
} // namespace day_02
