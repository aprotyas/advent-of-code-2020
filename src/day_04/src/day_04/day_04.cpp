#include <day_04/day_04.h>

namespace day_04 {

std::vector<Passport> parse_input(const std::vector<std::string> &in) {
    std::vector<Passport> passports;
    std::unordered_map<std::string, std::string> temp_pass;
    std::vector<std::string> temp_fields;
    std::string buffer_col, buffer_sp; // buffers till colons and spaces
    for (auto &line : in) {
        if (!line.length()) {
            if (temp_fields.size()) {
                assert(!temp_fields.size() % 2);
                for (auto i{0}; i < temp_fields.size(); i += 2) {
                    temp_pass[temp_fields[i]] = temp_fields[i + 1];
                }
                passports.push_back(temp_pass);
            }
            temp_fields.clear();
            temp_pass.clear();
            continue;
        } else {
            std::stringstream check_col{line};
            while (std::getline(check_col, buffer_col, ':')) {
                std::stringstream check_sp{buffer_col};
                while (std::getline(check_sp, buffer_sp, ' ')) {
                    temp_fields.push_back(buffer_sp);
                }
            }
        }
    }
    return passports;
}

uint32_t part_one(std::vector<Passport> &in) {
    uint32_t valid{};
    for (auto &pass : in) {
        valid += static_cast<uint32_t>(part_01::is_valid(pass));
    }
    return valid;
}

uint32_t part_two(std::vector<Passport> &in) {
    uint32_t valid{};
    for (auto &pass : in) {
        valid += static_cast<uint32_t>(part_02::is_valid(pass));
    }
    return valid;
}

namespace part_01 {
bool is_valid(Passport &pass) {
    return pass.size() == Passport::num_fields ||
           (pass.size() == Passport::num_fields - 1 && !pass.find("cid"));
}
} // namespace part_01

namespace part_02 {
bool is_valid(Passport &pass) {
    /*
     *   byr (Birth Year) - four digits; at least 1920 and at most 2002.
     *   iyr (Issue Year) - four digits; at least 2010 and at most 2020.
     *   eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
     *   hgt (Height) - a number followed by either cm or in:
     *       If cm, the number must be at least 150 and at most 193.
     *       If in, the number must be at least 59 and at most 76.
     *   hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
     *   ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
     *   pid (Passport ID) - a nine-digit number, including leading zeroes.
     *   cid (Country ID) - ignored, missing or not.
     */
    if (!part_01::is_valid(pass)) {
        return false;
    }

    else {
        bool valid_byr, valid_iyr, valid_eyr, valid_hgt, valid_hcl, valid_ecl,
            valid_pid, valid_cid;
        std::string byr, iyr, eyr, hgt, hcl, ecl, pid, cid;
        byr = pass["byr"];
        iyr = pass["iyr"];
        eyr = pass["eyr"];
        hgt = pass["hgt"];
        hcl = pass["hcl"];
        ecl = pass["ecl"];
        pid = pass["pid"];
        cid = pass["cid"];

        if (!(byr.length() == 4 && stoi(byr) >= 1920 && stoi(byr) <= 2002)) {
            return false;
        }

        if (!(iyr.length() == 4 && stoi(iyr) >= 2010 && stoi(iyr) <= 2020)) {
            return false;
        }

        if (!(eyr.length() == 4 && stoi(eyr) >= 2020 && stoi(eyr) <= 2030)) {
            return false;
        }

        bool cm, in;
        if ((cm = hgt.find("cm") != std::string::npos) ||
            (in = hgt.find("in") != std::string::npos)) {
            std::stringstream height{hgt};
            std::string n_height;
            if (cm) {
                std::getline(height, n_height, 'c');
                if (!(stoi(n_height) >= 150 && stoi(n_height) <= 193)) {
                    return false;
                }
            } else {
                std::getline(height, n_height, 'i');
                if (!(stoi(n_height) >= 59 && stoi(n_height) <= 76)) {
                    return false;
                }
            }
        } else {
            return false;
        }

        size_t hash;
        if ((hash = hcl.find("#")) != std::string::npos) {
            std::string color{hcl.substr(hash + 1)};
            if (!(color.length() == 6)) {
                return false;
            } else {
                for (auto &c : color) {
                    if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f'))) {
                        return false;
                    }
                }
            }
        } else {
            return false;
        }

        std::vector<std::string> ecl_list{{"amb"}, {"blu"}, {"brn"}, {"gry"},
                                          {"grn"}, {"hzl"}, {"oth"}};
        if (std::find(ecl_list.begin(), ecl_list.end(), ecl) ==
            ecl_list.end()) {
            return false;
        }

        uint32_t n_pid;
        if (pid.length() == 9) {
            try {
                n_pid = stoi(pid);
            } catch (const std::invalid_argument &ia) {
                return false;
            }
        } else {
            return false;
        }

        // passed all tests
        return true;
    }
}
} // namespace part_02
} // namespace day_04
