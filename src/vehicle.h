#ifndef VEHICLE_H_
#define VEHICLE_H_

class Vehicle
{
public:
    Vehicle(int id) : _id(id) {}
    void operator()();

private:
    int _id;
};

#endif