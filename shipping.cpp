// CLASS: shipping.cpp
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// shipping.cpp is the implementation of the interface shipping.h.
// shipping.cpp defines a constructor that recieves a pointer to a Prepare Event, passes on the parameters from the Prepare Event to the super constructor of Event
// in order to create a new Shipping Event, while also setting the arrivalTime to be the same as that of the Prepare Events.
// Because Event has a pure virtual method print() making it an abstract class, Shipping therefore must implement this method itself to avoid becoming an abstract class as well.
// Here you can see an implementation of the print() method for a Shipping object.
// Has a default implementation of a destructor so that Events pure virtual destructor will correctly call the subclass destructor.
//-----------------------------------------

#include "shipping.h"
#include "prepare.h"


#include <string>
#include <iostream>
using namespace std;

Shipping::Shipping(Prepare *prepare)    : Event((prepare->getTime() + prepare->getPrepTime()), prepare->getPrice(), prepare->getID(), prepare->getCustomerType())
{
    setArrivalTime(prepare->getArrivalTime());
}

Shipping::~Shipping()
{

}

void Shipping::print()
{
    cout << "TIME: " << this->getTime() << " -> Order " << this->getID() << " (" << this->getCustomerType() <<", $" << this->getPrice() << ")" << " has been shipped.";
}
