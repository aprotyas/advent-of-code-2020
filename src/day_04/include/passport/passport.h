#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

class Passport {
public:
    Passport(std::unordered_map<std::string, std::string> f);
    ~Passport() = default;
    size_t size() const;
    bool find(const std::string &&val) const;
    std::string operator[](std::string key);
    friend std::ostream &operator<<(std::ostream &os, const Passport &pass);

    static constexpr uint32_t num_fields = 8;

private:
    std::unordered_map<std::string, std::string> fields;
};
