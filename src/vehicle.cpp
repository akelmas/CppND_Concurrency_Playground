
#include <iostream>
#include "vehicle.h"


void Vehicle::operator()(){
     std::cout << "Vehicle #" << _id << " has been created" << std::endl;
}