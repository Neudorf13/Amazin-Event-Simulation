// CLASS: prepare.cpp
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// prepare.cpp implements the interface prepare.h.
// prepare.cpp defines a constructor that recieves a pointer to an Arrival event, passes on the standard event paramaters to the super constructor for Event to create
// a new Prepare Event, but also within the con, initalizes a new varaible prepTime that is unique to Prepare Events, and is calculated based on the price of the event,
// as well as passes on the arrivalTime that was initalized in the Arrival event.
// There is also included a getter for the prepTime variables.
// Because Event has a pure virtual method print() making it an abstract class, Prepare therefore must implement this method itself to avoid becoming an abstract class as well.
// Here you can see an implementation of the print() method for a Prepare object.
// Has a default implementation of a destructor so that Events pure virtual destructor will correctly call the subclass destructor.
//-----------------------------------------

#include "prepare.h"
#include "event.h"

#include <iostream>
using namespace std;


Prepare::Prepare(Arrival *arrival)  : Event(arrival->getTime(), arrival->getPrice(),arrival->getID(), arrival->getCustomerType())
{
    prepTime = (arrival->getPrice() / 200) + 1;
    setArrivalTime(arrival->getArrivalTime());
}

Prepare::~Prepare()
{

}

int Prepare::getPrepTime()
{
    return prepTime;
}

void Prepare::print()
{
    cout << "TIME: " << this->getTime() << " -> Order " << this->getID() << " (" << this->getCustomerType()  << ", $" << this->getPrice() << ") " << " is being prepared (prep. time = " << this->getPrepTime() << ")." <<endl;
}


