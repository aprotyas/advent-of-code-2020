#include <day_02/day_02.h>

namespace day_02{
    namespace part1{
        PasswordPolicy::PasswordPolicy(char l, uint32_t mi, uint32_t ma)
            : letter(l), min(mi), max(ma)
        {
        }
        
        PasswordPolicy::PasswordPolicy(PasswordPolicy&& p)
            : letter(p.letter), min(p.min), max(p.max)
        {
        }
        
        PasswordPolicy::PasswordPolicy(const PasswordPolicy& p)
            : letter(p.letter), min(p.min), max(p.max)
        {
        }
        
        const char& PasswordPolicy::get_policy_letter() const { return letter; }
        const uint32_t& PasswordPolicy::get_policy_min() const { return min; }
        const uint32_t& PasswordPolicy::get_policy_max() const { return max; }
        
        Password::Password(std::string pw, PasswordPolicy p)
            : pass(pw), policy(p)
        {
        }
        
        Password::Password(Password&& p)
            : pass(p.pass), policy(p.policy)
        {
        }
        
        Password::Password(const Password& p)
            : pass(p.pass), policy(p.policy)
        {
        }
        
        
        const std::string& Password::get_password() const { return pass; }
        const PasswordPolicy& Password::get_policy() const { return policy; }
        bool Password::is_valid() const{
            std::uint32_t count {static_cast<uint32_t>(std::count(pass.begin(), pass.end(), policy.get_policy_letter()))};
            return count >= policy.get_policy_min() && count <= policy.get_policy_max();
        }
        std::vector<Password> read_file(std::string fname){
            std::string line{};
            std::vector<Password> buffer{};
            std::ifstream ifs(fname);
            while(std::getline(ifs, line)){
                uint32_t min{};
                uint32_t max{};
                uint32_t num_delim_pos{};
                char policy_letter{};
                std::string password{};
                for(uint32_t idx {0}; idx < line.size(); idx++){
                    if(line[idx] == '-'){
                        num_delim_pos = idx;
                        // reached the number delimiter
                        min = std::stoi(line.substr(0,num_delim_pos));
                    }
                    if(line[idx] == ' '){
                        max = std::stoi(line.substr(num_delim_pos + 1, idx - num_delim_pos - 1));
                        policy_letter = line[idx + 1];
                        password = line.substr(idx + 4, line.size());
                        break;
                    }
                }
                buffer.push_back({password, {policy_letter, min, max}});
            }
            return buffer;
        }
    }
    
    namespace part2{
        PasswordPolicy::PasswordPolicy(char l, uint32_t le, uint32_t ri)
            : letter(l), left(le), right(ri)
        {
        }
        
        PasswordPolicy::PasswordPolicy(PasswordPolicy&& p)
            : letter(p.letter), left(p.left), right(p.right)
        {
        }
        
        PasswordPolicy::PasswordPolicy(const PasswordPolicy& p)
            : letter(p.letter), left(p.left), right(p.right)
        {
        }
        
        const char& PasswordPolicy::get_policy_letter() const { return letter; }
        const uint32_t& PasswordPolicy::get_policy_left() const { return left; }
        const uint32_t& PasswordPolicy::get_policy_right() const { return right; }
        
        Password::Password(std::string pw, PasswordPolicy p)
            : pass(pw), policy(p)
        {
        }
        
        Password::Password(Password&& p)
            : pass(p.pass), policy(p.policy)
        {
        }
        
        Password::Password(const Password& p)
            : pass(p.pass), policy(p.policy)
        {
        }
        
        
        const std::string& Password::get_password() const { return pass; }
        const PasswordPolicy& Password::get_policy() const { return policy; }
        bool Password::is_valid() const{
            uint32_t l_idx {policy.get_policy_left() - 1};
            uint32_t r_idx {policy.get_policy_right() - 1};
            char c {policy.get_policy_letter()};
            /*
            std::cout << "Password: " << pass << ", Policy letter: " << c << std::endl;
            bool _vleft {pass[l_idx] == c};
            bool _vright {pass[r_idx] == c};
            if(_vleft == _vright){
                std::cout << "Invalid: (" << pass << ")   letter: " << c << ", left: " << l_idx + 1 << ", right: " << r_idx + 1 << std::endl;
                return false;
            }
            else{
                std::cout << "Valid: (" << pass << ")   letter: " << c << ", left: " << l_idx + 1 << ", right: " << r_idx + 1 << std::endl;
                return true;
            }
            */
            return (pass[l_idx] == c) != (pass[r_idx] == c);
        }
        std::vector<Password> read_file(std::string fname){
            std::string line{};
            std::vector<Password> buffer{};
            std::ifstream ifs(fname);
            int line_num {1};
            while(std::getline(ifs, line)){
                uint32_t left{};
                uint32_t right{};
                uint32_t num_delim_pos{};
                char policy_letter{};
                std::string password{};
                for(uint32_t idx {0}; idx < line.size(); idx++){
                    if(line[idx] == '-'){
                        num_delim_pos = idx;
                        // reached the number delimiter
                        left = std::stoi(line.substr(0,num_delim_pos));
                    }
                    if(line[idx] == ' '){
                        right = std::stoi(line.substr(num_delim_pos + 1, idx - num_delim_pos - 1));
                        policy_letter = line[idx + 1];
                        password = line.substr(idx + 4, line.size());
                        break;
                    }
                }
                buffer.push_back({password, {policy_letter, left, right}});
            }
            return buffer;
        }
    }

    uint32_t part_one(std::vector<part1::Password> input){
        uint32_t valid {0};
        for(const auto& pw: input){
            valid += static_cast<uint32_t>(pw.is_valid());
        }
        return valid;
    }

    uint32_t part_two(std::vector<part2::Password> input){
        uint32_t valid {0};
        for(const auto& pw: input){
            valid += static_cast<uint32_t>(pw.is_valid());
        }
        return valid;
    }
}

std::ostream& day_02::operator<<(std::ostream& os, const std::vector<day_02::part1::Password>& passwords){
    return os;
}

std::ostream& day_02::operator<<(std::ostream& os, const std::vector<day_02::part2::Password>& passwords){
    return os;
}
