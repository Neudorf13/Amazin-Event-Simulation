// CLASS: event.cpp
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// event.cpp is the implementation of the event.h interface. event.cpp implements a constructor that will be called when we want to create any class that is a subclass of event
// as well as implements the necessary getters and setters for the Event class instance variables to be used when we need access to these variables within it's subclasses.
// Includes an empty implementation of it's destructor.
//-----------------------------------------

#include "event.h"

#include <string>
using namespace std;

Event::Event(int time, int price, int id, string customerType)   :   time(time), price(price), id(id), customerType(customerType)
{
    
}

Event::~Event()
{

}

int Event::getPrice()
{
    return price;
}

int Event::getTime()
{
    return time;
}

int Event::getID()
{
    return id;
}

string Event::getCustomerType()
{
    return customerType;
}

int Event::getArrivalTime()
{
    return arrivalTime;
}

void Event::setTime(int newTime)
{
    time = newTime;
}

void Event::setArrivalTime(int initTime)
{
    arrivalTime = initTime;
}