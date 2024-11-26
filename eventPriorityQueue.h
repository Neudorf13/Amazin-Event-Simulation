// CLASS: eventPriorityQueue.h
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// eventPriorityQueue.h is the interface that describes the class EventPriorityQueue.
// EventPriorityQueue has pointers to both the front and back of the queue, as well as functions such as:
// constructor, destructor, enqueue and dequeue, isEmpty and a printQueue method which was utilized during testing.
//-----------------------------------------

#pragma once
#include "eventNode.h"

class EventPriorityQueue
{

    private:
        
        EventNode *front;
        EventNode *back;

    public:
        EventPriorityQueue();
        ~EventPriorityQueue();
        void enqueue(EventNode *e);
        EventNode* dequeue();
        bool isEmpty();
        void printQueue();

};