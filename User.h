#pragma once
#include <string>

class User {
private:
    std::string username;
    std::string password;
    bool isAdmin;
public:
    User();
    User(const std::string& username, const std::string& password, bool isAdmin = false);
    std::string getUsername() const;
    std::string getPassword() const;
    bool getIsAdmin() const;
    void setPassword(const std::string&);
    std::string serialize() const;
    static User deserializeLine(const std::string& line);
};
