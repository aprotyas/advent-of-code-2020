#pragma once
#include <stdint.h>

class PasswordPolicy {
  public:
    PasswordPolicy(char l, uint32_t _a, uint32_t _b);
    PasswordPolicy(PasswordPolicy &&p);
    PasswordPolicy(const PasswordPolicy &p);
    ~PasswordPolicy() = default;
    const char &get_policy_letter() const;
    const uint32_t &get_policy_a() const;
    const uint32_t &get_policy_b() const;

  private:
    char letter;
    uint32_t a;
    uint32_t b;
};
