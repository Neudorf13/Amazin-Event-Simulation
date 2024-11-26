// CLASS: shippingNode.cpp
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// shippingNode.cpp is the implemenation of the interface shippingNode.h.
// shippingNode.cpp defines a a constructor that recieves a pointer to an Arrival Event, stores that pointer in its data varariable and inits the next pointer to nullptr.
// Also includes the necessary getters and setters for its instance variables next and data.
// Includes a destructor that frees the memory for data and sets its instance variables to nullptr to avoid any hanging pointers.
//-----------------------------------------

#include "shippingNode.h"
#include "arrival.h"


ShippingNode::ShippingNode(Arrival *newNode)    : data(newNode)
{
    next=nullptr;
}

ShippingNode::~ShippingNode()
{
    delete data;
    data = nullptr;
    next = nullptr;
}

void ShippingNode::setNext(ShippingNode *nextNode)
{
    this->next = nextNode;
}

ShippingNode* ShippingNode::getNext()
{
    return this->next;
}

Arrival* ShippingNode::getData()
{
    return this->data;
}