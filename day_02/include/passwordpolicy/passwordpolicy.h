#pragma once
#include <stdint.h>

/*
 *  A PasswordPolicy object contains the letter specified
 *  by the policy, and the two unsigned integral bounds
 *  `a` and `b`.
 *
 *  Note `a` and `b` are used differently depending on the
 *  context!
 *  See part1::is_valid() vs part2::is_valid()
 */

class PasswordPolicy {
public:
    PasswordPolicy(char l, uint32_t _a, uint32_t _b);
    PasswordPolicy(PasswordPolicy &&p);      // move
    PasswordPolicy(const PasswordPolicy &p); // copy
    ~PasswordPolicy() = default;
    const char &get_policy_letter() const;
    const uint32_t &get_policy_a() const;
    const uint32_t &get_policy_b() const;

private:
    char letter;
    uint32_t a;
    uint32_t b;
};
