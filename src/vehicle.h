#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <string>

class Vehicle
{
public:
    Vehicle() : _id(0) {}
    Vehicle(int id) : _id(id) {}
    void operator()();
    void addID(int id);
    void setName(std::string name);
    void printID();
    void printName();

private:
    int _id;
    std::string _name;
};

#endif