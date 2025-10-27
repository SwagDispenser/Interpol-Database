#include "Person.h"

Person::Person() : id(""), name(""), nationality(""), age(0) {}
Person::Person(const std::string& id_, const std::string& name_, const std::string& nat, int age_)
    : id(id_), name(name_), nationality(nat), age(age_) {}
Person::Person(const Person& other) : id(other.id), name(other.name), nationality(other.nationality), age(other.age) {}
Person::Person(Person&& other) noexcept
    : id(std::move(other.id)), name(std::move(other.name)), nationality(std::move(other.nationality)), age(other.age) {
    other.age = 0;
}
Person::~Person() {
    std::cout << "Destroying Person: " << id << "\n";
}

std::string Person::getId() const { return id; }
void Person::setId(const std::string& v) { id = v; }
std::string Person::getName() const { return name; }
void Person::setName(const std::string& v) { name = v; }
std::string Person::getNationality() const { return nationality; }
void Person::setNationality(const std::string& v) { nationality = v; }
int Person::getAge() const { return age; }
void Person::setAge(int v) { age = v; }

void Person::printInfo() const {
    std::cout << "[" << getCategory() << "] ID: " << id << ", Name: " << name
              << ", Nationality: " << nationality << ", Age: " << age << "\n";
}
