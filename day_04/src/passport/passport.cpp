#include <passport/passport.h>

Passport::Passport(std::unordered_map<std::string, std::string> f)
    : fields(f) {}

size_t Passport::size() const { return fields.size(); }

bool Passport::find(const std::string &&val) const {
    return fields.find(val) != fields.end();
}

std::string Passport::operator[](std::string key) { return fields[key]; }

std::ostream &operator<<(std::ostream &os, const Passport &pass) {
    os << '[' << '\n';
    for (const auto &[k, v] : pass.fields) {
        os << '\t' << k << ": " << v << '\n';
    }
    os << ']';
    return os;
}
