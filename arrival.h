// CLASS: arrival.h
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// arrival.h is the interface that declares the Arrival class.
// The Arrival class is a subclass of the abstract class Event thus inheriting the parameters laid out in event.h, while also inlcuding it's own class class variable for 
// id tracking. Arrival has one constructor implementation that takes the parameters required for an Event, as well declares that the arrival class will have it's own
// implementation of the pure virtual method from Event, print().
// Includes a declared destructor
//-----------------------------------------
#pragma once
#include "event.h"

class Arrival : public Event
{
    private:
        int static idCounter;

    public:
        Arrival(int time, int price, string customerType);
        ~Arrival();
        void print();
};