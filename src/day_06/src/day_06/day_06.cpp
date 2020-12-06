#include <day_06/day_06.h>

namespace day_06 {

uint32_t part_one(const std::vector<Group> &groups) {
    uint32_t ans{};
    for (auto &group : groups) {
        ans += group.unique_answers();
    }
    return ans;
}

uint32_t part_two(const std::vector<Group> &groups) {
    uint32_t ans{};
    for (auto &group : groups) {
        ans += group.common_answers();
    }
    return ans;
}

std::vector<Group> parse_groups(std::vector<std::string> ans) {
    std::vector<Group> groups;
    std::vector<std::string> temp_ans;
    uint32_t count{};
    for (auto it = ans.begin(); it != ans.end(); it++) {
        if (!(it->length()) || it == std::prev(ans.end())) {
            if (it == std::prev(ans.end())) {
                temp_ans.push_back(*it);
            }
            assert(!temp_ans.size());
            groups.push_back(
                {temp_ans, static_cast<uint32_t>(temp_ans.size())});
            temp_ans.clear();
        } else {
            temp_ans.push_back(*it);
        }
    }
    return groups;
}
} // namespace day_06
