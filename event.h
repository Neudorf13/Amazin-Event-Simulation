// CLASS: event.h
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// event.h is the interface for the abstract class Event. As can be seen, Event has many private instance varibles that describe the various components of an Event.
// Described in Events set of methods are the various necessary getters and setters for use of working with Events variables while working with a subclass of Event.
// As can be seen there is also a pure virtual method print()  that makes Event an abstract class in the first place, and must be implemented by all non-abstract subclasses
// of Event. Finally, Event also includes a constructor that will be called when creating subclass obects of Event.
// Includes a pure virtual destructor so that when delete is called on a statically typed Event object, the correct subclass destructor will be called.
//-----------------------------------------
#pragma once
#include <string>
using namespace std;

class Event
{
    private:
        int id;
        int time;
        int price;
        int arrivalTime;
        string customerType;

    public:
        virtual void print() = 0;
        Event(int time, int price, int id, string customerType);
        virtual ~Event() = 0;
        int getPrice();
        int getTime();
        int getID();
        int getArrivalTime();
        string getCustomerType();
        void setTime(int initTime);
        void setArrivalTime(int initTime);
        
};