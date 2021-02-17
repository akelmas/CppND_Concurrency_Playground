
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
void Vehicle::setName(std::string name){
     _name=name;
}
void Vehicle::printName()
{
     std::cout<< "Vehicle Name="<<_name<<std::endl;
}