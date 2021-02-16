#ifndef VEHICLE_H_
#define VEHICLE_H_

class Vehicle
{
public:
    Vehicle() : _id(0) {}
    Vehicle(int id) : _id(id) {}
    void operator()();
    void addID(int id);
    void printID();

private:
    int _id;
};

#endif