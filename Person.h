#include "ISerializable.h"
#include <string>
#include <iostream>

class Person : public ISerializable {

protected:
    std::string id;
    std::string name;
    std::string nationality;
    int age;

public:
    Person();
    Person(const std::string& id, const std::string& name, const std::string& nat, int age);
    Person(const Person& other);
    Person(Person&& other) noexcept;
    virtual ~Person();

    std::string getId() const;
    void setId(const std::string&);
    std::string getName() const;
    void setName(const std::string&);
    std::string getNationality() const;
    void setNationality(const std::string&);
    int getAge() const;
    void setAge(int);

    virtual std::string getCategory() const = 0;

    virtual void printInfo() const;
};
