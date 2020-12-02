#pragma once
#include <passwordpolicy/passwordpolicy.h>

#include <iterator>
#include <string>
#include <vector>

/*
 *  A Password object simply has the string representation
 *  of the password, and a specific PasswordPolicy instance
 *  to go with it. Note that the concept of ``validity`` is
 *  stripped away from a password and is only used when
 *  the context requires it.
 */

class Password {
public:
    Password(std::string pw, PasswordPolicy p);
    Password(Password &&p);      // move
    Password(const Password &p); // copy
    ~Password() = default;
    const std::string &get_password() const;
    const PasswordPolicy &get_policy() const;

private:
    std::string pass;
    PasswordPolicy policy;
};
