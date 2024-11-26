// CLASS: arrival.cpp
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
// arrival.cpp is the implementation of the arrival.h interface. 
// It defines the class variable to track id numbers, as well the constructor for an Arrival object which calls the super constructor of Event to initalize the Arrival
// object as an Arrival Event, while incrememnting the idCounter for the next arrival.
// Because Event has a pure virtual method print() making it an abstract class, Arrival therefore must implement this method itself to avoid becoming an abstract class as well.
// Here you can see an implementation of the print() method for an Arrival object.
// Has a default implementation of a destructor so that Events pure virtual destructor will correctly call the subclass destructor.
//-----------------------------------------

#include "arrival.h"
#include "event.h"

#include <string>
#include <iostream>
using namespace std;

int Arrival::idCounter = 1; //static variable that starts with id=1, and is incremented every time a new Arrival is created.

Arrival::Arrival(int time, int price, string customerType) : Event(time,price,idCounter,customerType)
{
    idCounter++;
}

Arrival::~Arrival()
{
    
}

void Arrival::print()   //temp method
{
    cout << "TIME: " << this->getTime() << " -> Order " << this->getID() << " (" << this->getCustomerType() <<", $" << this->getPrice() << ") " << " arrives." << endl;

}