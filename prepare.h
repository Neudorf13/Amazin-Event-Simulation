// CLASS: prepare.h
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// prepare.h is the interface for the Prepare class.
// Prepare includes a unique prepTime variable, as well as the instance variables declared in its superclass Event.
// Prepare has a constructor that recieves a pointer to an Arrival Event used to initalized the Prepare Event, a getter for the prepTime variable, and an implementation
// of the pure virtual method print() from its superclass Event.
// Includes a declared destructor
//-----------------------------------------

#pragma once
#include "event.h"
#include "arrival.h"

class Prepare : public Event
{

    private:

        int prepTime;

    public:
        
        Prepare(Arrival *arrival);
        ~Prepare();
        int getPrepTime();
        void print();
};