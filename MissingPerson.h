#pragma once
#include "Person.h"
#include <string>

class MissingPerson : public Person {
private:
    std::string lastSeenLocation;
    std::string missingSince;
public:
    MissingPerson();
    MissingPerson(const std::string& id, const std::string& name, const std::string& nat, int age,
                  const std::string& lastSeen, const std::string& missingSince);

    MissingPerson(const MissingPerson& other);
    MissingPerson(MissingPerson&& other) noexcept;
    ~MissingPerson() override;

    std::string getCategory() const override;
    std::string serialize() const;
    void deserialize(const std::string& line) override;

    void printInfo() const override;
    bool matches(const std::string& key) const;
};
