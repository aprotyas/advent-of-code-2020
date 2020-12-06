#include <passwordpolicy/passwordpolicy.h>

// Constructors and getters, nothing fancy

PasswordPolicy::PasswordPolicy(char l, uint32_t _a, uint32_t _b)
    : letter(l), a(_a), b(_b) {}

PasswordPolicy::PasswordPolicy(PasswordPolicy &&p)
    : letter(p.letter), a(p.a), b(p.b) {}

PasswordPolicy::PasswordPolicy(const PasswordPolicy &p)
    : letter(p.letter), a(p.a), b(p.b) {}

const char &PasswordPolicy::get_policy_letter() const { return letter; }
const uint32_t &PasswordPolicy::get_policy_a() const { return a; }
const uint32_t &PasswordPolicy::get_policy_b() const { return b; }
