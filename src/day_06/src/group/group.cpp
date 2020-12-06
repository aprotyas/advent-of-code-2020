#include <group/group.h>

Group::Group(const std::vector<std::string> &ans, uint32_t sz)
    : answers(create_answer_map(ans)), group_size(sz) {}

std::unordered_map<char, uint32_t>
create_answer_map(const std::vector<std::string> &ans) {
    std::unordered_map<char, uint32_t> ans_map;
    for (auto &a : ans) {
        for (auto &ch : a) {
            ans_map[ch]++;
        }
    }
    return ans_map;
}

uint32_t Group::unique_answers() const { return answers.size(); }

uint32_t Group::common_answers() const {
    uint32_t ans{};
    for (const auto &[a, freq] : answers) {
        ans += static_cast<uint32_t>(freq == group_size);
    }
    return ans;
}
