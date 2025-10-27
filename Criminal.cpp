#include "Criminal.h"
#include <sstream>

Criminal::Criminal() : Person(), crimeType(""), isCaptured(false) {}
Criminal::Criminal(const std::string& id_, const std::string& name_, const std::string& nat, int age_,
                   const std::string& crimeType_, bool isCaptured_)
    : Person(id_, name_, nat, age_), crimeType(crimeType_), isCaptured(isCaptured_) {}

Criminal::Criminal(const Criminal& other)
    : Person(other), crimeType(other.crimeType), isCaptured(other.isCaptured) {}
Criminal::Criminal(Criminal&& other) noexcept
    : Person(std::move(other)), crimeType(std::move(other.crimeType)), isCaptured(other.isCaptured) {
    other.isCaptured = false;
}
Criminal::~Criminal() { std::cout << "Destroying Criminal: " << id << "\n"; }

std::string Criminal::getCrimeType() const { return crimeType; }
void Criminal::setCrimeType(const std::string& v) { crimeType = v; }
bool Criminal::getIsCaptured() const { return isCaptured; }
void Criminal::setIsCaptured(bool v) { isCaptured = v; }

std::string Criminal::getCategory() const { return "Criminal"; }

// CSV format: Criminal,id,name,nationality,age,crimeType,isCaptured
std::string Criminal::serialize() const {
    std::ostringstream oss;
    oss << "Criminal," << id << "," << name << "," << nationality << "," << age << ","
        << crimeType << "," << (isCaptured ? "1" : "0");
    return oss.str();
}

void Criminal::deserialize(const std::string& line) {
    // expects CSV fields
    std::istringstream iss(line);
    std::string token;
    std::getline(iss, token, ','); // type
    std::getline(iss, id, ',');
    std::getline(iss, name, ',');
    std::getline(iss, nationality, ',');
    std::getline(iss, token, ','); age = std::stoi(token);
    std::getline(iss, crimeType, ',');
    std::getline(iss, token, ','); isCaptured = (token == "1");
}

void Criminal::markCaptured() { isCaptured = true; }

void Criminal::printInfo() const {
    Person::printInfo();
    std::cout << "  Crime: " << crimeType << ", Captured: " << (isCaptured ? "Yes" : "No") << "\n";
}

bool Criminal::matches(const std::string& key) const {
    return id == key || name.find(key) != std::string::npos || nationality.find(key) != std::string::npos;
}
