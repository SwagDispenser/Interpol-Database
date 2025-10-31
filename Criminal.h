#include "Person.h"
#include <string>

class Criminal : public Person {

private:
    std::string crimeType;
    bool isCaptured;

public:
    Criminal();
    Criminal(const std::string& id, const std::string& name, const std::string& nat, int age,
             const std::string& crimeType, bool isCaptured);

    Criminal(const Criminal& other);
    Criminal(Criminal&& other) noexcept;
    ~Criminal() override;

    std::string getCrimeType() const;
    void setCrimeType(const std::string&);
    bool getIsCaptured() const;
    void setIsCaptured(bool);

    std::string getCategory() const;
    std::string serialize() const;
    void deserialize(const std::string& line);

    void markCaptured();
    void printInfo() const override;
    bool matches(const std::string& key) const;
};
