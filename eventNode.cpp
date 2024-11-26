// CLASS: eventNode.cpp
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// eventNode.cpp is the implementation of the interface eventNode.h.
// eventNode.cpp defines the various methods declared within the interface, including a constructor which takes a pointer to any subclass of Event, as well as initalizing
// the next pointer of the node to nullptr. Included as well are the necessary getters and setters for the eventNode class.
// Includes a destructor that sets instance variables to nullptr to avoid any hanging pointers.
//-----------------------------------------

#include "eventNode.h"
#include "event.h"

EventNode::EventNode(Event *newNode) : data(newNode), next(nullptr)
{
    
}

EventNode::~EventNode()
{
    data = nullptr;
    next = nullptr;
}

EventNode* EventNode::getNext()
{
    return this->next;
}

void EventNode::setNext(EventNode *nextNode)
{
    this->next = nextNode;
}

Event* EventNode::getData()
{
    return this->data;
}