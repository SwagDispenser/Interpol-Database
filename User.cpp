#include "User.h"
#include <sstream>

User::User() : username(""), password(""), isAdmin(false) {}
User::User(const std::string& u, const std::string& p, bool a) : username(u), password(p), isAdmin(a) {}

std::string User::getUsername() const { return username; }
std::string User::getPassword() const { return password; }
bool User::getIsAdmin() const { return isAdmin; }
void User::setPassword(const std::string& p) { password = p; }

std::string User::serialize() const {
    // per requirement format: username:password
    std::ostringstream oss;
    oss << username << ":" << password;
    return oss.str();
}

User User::deserializeLine(const std::string& line) {
    auto pos = line.find(':');
    if (pos == std::string::npos) {
        return User("", "", false);
    }
    std::string u = line.substr(0, pos);
    std::string p = line.substr(pos + 1);
    bool admin = (u == "admin"); // admin flagged by username == "admin"
    return User(u, p, admin);
}
