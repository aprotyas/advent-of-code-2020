#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<char, uint32_t>
create_answer_map(const std::vector<std::string> &ans);

class Group {
public:
    Group(const std::vector<std::string> &ans, uint32_t sz = 1);
    ~Group() = default;
    uint32_t unique_answers() const;
    uint32_t common_answers() const;

private:
    std::unordered_map<char, uint32_t> answers;
    uint32_t group_size;
};
