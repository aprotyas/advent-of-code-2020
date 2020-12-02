#pragma once
#include <vector>
#include <iterator>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

namespace day_02{
    namespace part1{
        class PasswordPolicy{
            public:
                PasswordPolicy(char l, uint32_t mi, uint32_t ma);
                PasswordPolicy(PasswordPolicy&& p);
                PasswordPolicy(const PasswordPolicy& p);
                ~PasswordPolicy() = default;
                const char& get_policy_letter() const;
                const uint32_t& get_policy_min() const;
                const uint32_t& get_policy_max() const;
        
            private:
                char letter;
                uint32_t min;
                uint32_t max;
        };
        
        class Password{
            public:
                Password(std::string pw, PasswordPolicy p);
                Password(Password&& p);
                Password(const Password& p);
                ~Password() = default;
                const std::string& get_password() const;
                const PasswordPolicy& get_policy() const;
                bool is_valid() const;
        
            private:
                std::string pass;
                PasswordPolicy policy;
        };
        std::vector<Password> read_file(std::string fname);
    }
    
    namespace part2{
        class PasswordPolicy{
            public:
                PasswordPolicy(char l, uint32_t le, uint32_t ri);
                PasswordPolicy(PasswordPolicy&& p);
                PasswordPolicy(const PasswordPolicy& p);
                ~PasswordPolicy() = default;
                const char& get_policy_letter() const;
                const uint32_t& get_policy_left() const;
                const uint32_t& get_policy_right() const;
        
            private:
                char letter;
                uint32_t left;
                uint32_t right;
        };
        
        class Password{
            public:
                Password(std::string pw, PasswordPolicy p);
                Password(Password&& p);
                Password(const Password& p);
                ~Password() = default;
                const std::string& get_password() const;
                const PasswordPolicy& get_policy() const;
                bool is_valid() const;
        
            private:
                std::string pass;
                PasswordPolicy policy;
        };
        std::vector<Password> read_file(std::string fname);
    }
    uint32_t part_one(std::vector<part1::Password> input);
    uint32_t part_two(std::vector<part2::Password> input);
    std::ostream& operator<<(std::ostream& os, const std::vector<part1::Password>& passwords);
    std::ostream& operator<<(std::ostream& os, const std::vector<part2::Password>& passwords);
}
