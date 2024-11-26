// CLASS: shippingNode.h
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// shippingNode.h is the interface for the ShippingNode class. 
// ShippingNode has a pointer to an Arrival Event called data that it will store, as well as a pointer to the next node in the linked data structure it will be used in.
// Includes a constructor that recieves an Arrival pointer to initalize the node, as well as the necessary getters and setters for its instance variables.
// Includes a destructor for ShippingNodes.
//-----------------------------------------

#pragma once
#include "arrival.h"

class ShippingNode
{
    private:
        Arrival *data;
        ShippingNode *next;
    
    public:
        ShippingNode(Arrival *newNode);
        ~ShippingNode();
        void setNext(ShippingNode *nextNode);
        ShippingNode *getNext();
        Arrival* getData();

};