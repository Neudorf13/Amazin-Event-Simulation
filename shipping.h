// CLASS: shipping.h
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// shipping.h is the interface for the Shipping class.
// Shipping has a constructor that recieves a pointer to a Prepare Event used to initalized the Shipping Event and an implementation
// of the pure virtual method print() from its superclass Event.
// Includes a declared destructor
//-----------------------------------------
#include "prepare.h"

class Shipping : public Event
{
    private:

    public:
        Shipping(Prepare *prepare);
        ~Shipping();
        void print();
};