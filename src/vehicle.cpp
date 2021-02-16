
#include <iostream>
#include "vehicle.h"


void Vehicle::operator()(){
     std::cout << "Vehicle #" << _id << " has been created" << std::endl;
}

void Vehicle::addID(int id) { _id = id; }
void Vehicle::printID()
{
     std::cout << "Vehicle ID=" << _id << std::endl;
}