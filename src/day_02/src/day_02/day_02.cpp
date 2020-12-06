#include <day_02/day_02.h>

/*
 *  Correct me if I'm wrong... I don't really know how big-O works
 *
 *  Space complexity: O(nm) - Need to create `n` Passwords
 *  of maximum size `m` and store in a vector of appropriate size
 *
 *  Time complexity: O(nm) - Have to go through `n` Passwords,
 *  parsing/checking validity of each password is an O(m) operation
 */

namespace day_02 {
/*
 *  As mentioned earlier, the meaning of password validity
 *  varies between the two parts of the puzzle.
 *  As such, is_valid() has been separated into two namespaces.
 */

namespace part1 {
bool is_valid(const Password &pw) {
    /*
     *  In part 1, a password is valid if there is at least
     *  `a` occurrences and at most `b` occurrences of the letter
     *  specified by the policy of that specific password.
     */

    std::string pass{pw.get_password()};
    PasswordPolicy policy{pw.get_policy()};
    // counting instances of `letter` in the password
    std::uint32_t count{static_cast<uint32_t>(
        std::count(pass.begin(), pass.end(), policy.get_policy_letter()))};
    // if a <= count <= b, return true. else return false
    return count >= policy.get_policy_a() && count <= policy.get_policy_b();
}
} // namespace part1

namespace part2 {
bool is_valid(const Password &pw) {
    /*
     *  In part 2, a password is valid if there is exactly
     *  one occurence of the letter specified by the policy
     *  in the 1-based indices `a` and `b` of the password
     *  string.
     *
     *  The truth value is an XOR operation between the
     *  presence of the letter at `a` and the presence of
     *  the letter at `b`
     */
    std::string pass{pw.get_password()};
    PasswordPolicy policy{pw.get_policy()};
    // converting from 1-based index to 0-based index
    uint32_t l_idx{policy.get_policy_a() - 1};
    uint32_t r_idx{policy.get_policy_b() - 1};
    char c{policy.get_policy_letter()};
    // XOR operation, since only one condition can be true
    // at a time
    return (pass[l_idx] == c) != (pass[r_idx] == c);
}
} // namespace part2

uint32_t part_one(std::vector<Password> input) {
    // part_one() calls part1::is_valid() to determine validity
    uint32_t valid{0};
    for (const auto &pw : input) {
        valid += static_cast<uint32_t>(part1::is_valid(pw));
    }
    return valid;
}

uint32_t part_two(std::vector<Password> input) {
    // part_two() calls part2::is_valid() to determine validity
    uint32_t valid{0};
    for (const auto &pw : input) {
        valid += static_cast<uint32_t>(part2::is_valid(pw));
    }
    return valid;
}

std::vector<Password> read_file(std::string fname) {
    /*
     *  - Create an input file stream from the given file name
     *  - Iterate through each line of the input file
     *      - Find '-' delimiter to get `a`/`b` for policy
     *      - Find ' ' after `a`/`b` to obtain the policy
     *      letter (right after ' ') and to obtain the actual
     *      policy (three characters to the right of the policy
     *      letter)
     *      3 is not a magic number, all password entries are
     *      separated like that
     *  - Instantiate Password/PasswordPolicy and push into a
     *  vector of Passwords
     */
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
                // reached the space after `b`
                b = std::stoi(
                    line.substr(num_delim_pos + 1, idx - num_delim_pos - 1));
                policy_letter = line[idx + 1];
                password = line.substr(idx + 4, line.size());
                break;
            }
        }
        // construct Password and PasswordPolicy instances using
        // move constructors, then push into vector of Passwords
        buffer.push_back({password, {policy_letter, a, b}});
    }
    return buffer;
}

std::ostream &operator<<(std::ostream &os,
                         const std::vector<Password> &passwords) {
    /*
     *  TO-DO
     *  Never implemented because didn't need it for debugging
     */
    return os;
}
} // namespace day_02
