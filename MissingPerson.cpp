#include "MissingPerson.h"
#include <sstream>

MissingPerson::MissingPerson() : Person(), lastSeenLocation(""), missingSince("") {}
MissingPerson::MissingPerson(const std::string& id_, const std::string& name_, const std::string& nat, int age_,
                             const std::string& lastSeen, const std::string& missingSince_)
    : Person(id_, name_, nat, age_), lastSeenLocation(lastSeen), missingSince(missingSince_) {}

MissingPerson::MissingPerson(const MissingPerson& other)
    : Person(other), lastSeenLocation(other.lastSeenLocation), missingSince(other.missingSince) {}
MissingPerson::MissingPerson(MissingPerson&& other) noexcept
    : Person(std::move(other)), lastSeenLocation(std::move(other.lastSeenLocation)), missingSince(std::move(other.missingSince)) {}
MissingPerson::~MissingPerson() { std::cout << "Destroying MissingPerson: " << id << "\n"; }

std::string MissingPerson::getCategory() const { return "MissingPerson"; }

std::string MissingPerson::serialize() const {
    std::ostringstream oss;
    oss << "MissingPerson," << id << "," << name << "," << nationality << "," << age << ","
        << lastSeenLocation << "," << missingSince;
    return oss.str();
}

void MissingPerson::deserialize(const std::string& line) {
    std::istringstream iss(line);
    std::string token;
    std::getline(iss, token, ','); // type
    std::getline(iss, id, ',');
    std::getline(iss, name, ',');
    std::getline(iss, nationality, ',');
    std::getline(iss, token, ','); age = std::stoi(token);
    std::getline(iss, lastSeenLocation, ',');
    std::getline(iss, missingSince, ',');
}

void MissingPerson::printInfo() const {
    Person::printInfo();
    std::cout << "  Last seen: " << lastSeenLocation << ", Missing since: " << missingSince << "\n";
}

bool MissingPerson::matches(const std::string& key) const {
    return id == key || name.find(key) != std::string::npos || lastSeenLocation.find(key) != std::string::npos;
}
