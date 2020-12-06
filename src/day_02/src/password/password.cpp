#include <password/password.h>

// Constructors and getters, nothing fancy

Password::Password(std::string pw, PasswordPolicy p) : pass(pw), policy(p) {}

Password::Password(Password &&p) : pass(p.pass), policy(p.policy) {}

Password::Password(const Password &p) : pass(p.pass), policy(p.policy) {}

const std::string &Password::get_password() const { return pass; }
const PasswordPolicy &Password::get_policy() const { return policy; }
