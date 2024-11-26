// CLASS: eventNode.h
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// eventNode.h is the interface that describes the EventNode class.
// The EventNode class is a relatively simple node class to be used with a linked data structure. It's data field will store a pointer to any subclass of the abstract type
// Event, as well as a pointer to the next EventNode in the data structure. 
// Described in it's list of functions are a constructor that recieves a pointer to an Event object, as well as necessary getters and setters for working with EventNode objects.
// Includes a destructor for EventNodes.
//-----------------------------------------
#pragma once
#include "event.h"

class EventNode
{
    private:
        Event *data;
        EventNode *next;

    public:
        EventNode(Event *newNode);
        ~EventNode();
        EventNode *getNext();
        void setNext(EventNode *nextNode);
        Event *getData();
};