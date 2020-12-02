#pragma once
#include <passwordpolicy/passwordpolicy.h>

#include <iterator>
#include <string>
#include <vector>

class Password {
  public:
    Password(std::string pw, PasswordPolicy p);
    Password(Password &&p);
    Password(const Password &p);
    ~Password() = default;
    const std::string &get_password() const;
    const PasswordPolicy &get_policy() const;

  private:
    std::string pass;
    PasswordPolicy policy;
};
