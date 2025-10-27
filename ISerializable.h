#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H
#include "string"



class ISerializable {
public:
    virtual std::string serialize();
    virtual void deserialize(const std::string&) = 0;
    virtual ~ISerializable() = default;
};

#endif //ISERIALIZABLE_H
