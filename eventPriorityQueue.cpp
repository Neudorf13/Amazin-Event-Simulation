// CLASS: eventPriorityQueue.cpp
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// eventPriorityQueue.cpp is the implementation of the interface eventPriorityQueue.h.
// eventPriorityQueue.cpp defines the functions described in the interface, including:
// constructor that simply initalizes the queue as empty, a destructor that if the queue is not empty when destroyed, goes through and destroyes the remaining nodes it stores,
// enqueue which recieves a pointer to an EventNode to add to the queue and will prioritize adding the new node to the list first in order of the nodes event data type's time
// and secondly by it's orderID value. Dequeue which simply removes the node at the front of the queue, sets the next node in the queue to be the new front, and returns
// the removed node. isEmpty simply returns true if the queue is empty, false otherwise. Included as well is a print method used for testing.
//-----------------------------------------

#include "eventPriorityQueue.h"
#include "event.h"

#include "prepare.h"
#include "arrival.h"
#include "shipping.h"

#include <iostream>

using namespace std;

//init empty queue
EventPriorityQueue::EventPriorityQueue()
{
    front = back = nullptr;
}

//if queue is not empty when destroyed, goes through and destroyes all nodes within the queue before being destroyed itself.
EventPriorityQueue::~EventPriorityQueue()
{
    if(front != nullptr)
    {
        EventNode *prev = nullptr;
        EventNode *curr = front;
        while(curr != nullptr)
        {
            prev = curr;
            curr=curr->getNext();
            delete prev;
        }
    }
    front = back = nullptr;
}

//adds a new EventNode to the queue, with priority of firstly time of the event, and in the case another node has the same time, the lower id number will come first
void EventPriorityQueue::enqueue(EventNode *e)
{
    if(front == nullptr)
    {
        front = back = e;
    }
    else
    {
        EventNode *curr = front;
        EventNode *prev = nullptr;
        while(curr != nullptr && e->getData()->getTime() > curr->getData()->getTime()) //if new eventNode has a time less then the current node
        {
            prev = curr;
            curr=curr->getNext();   
        }

        while(curr != nullptr && e->getData()->getTime() == curr->getData()->getTime() && e->getData()->getID() > curr->getData()->getID())
        {
            prev = curr;
            curr = curr->getNext();
        }
        
        if(prev != nullptr)
        {
            prev->setNext(e);
            e->setNext(curr);
            
        }
        else    //else is hit if new node should go in the front of the queue
        {
            e->setNext(curr);
            front = e;
        }
    }

}

//*****Does not clear tempNode from memory
//removes first node from queue and returns
EventNode* EventPriorityQueue::dequeue()
{
    EventNode *tempNode = nullptr;
    if(front != nullptr)
    {
        tempNode = front;
        front = front->getNext();
    }

    return tempNode;
}

//used for testing purposes
void EventPriorityQueue::printQueue()
{
    EventNode *curr = front;
    while(curr != nullptr)
    {
        cout << "Event Type: ";
        if(Arrival *a = dynamic_cast<Arrival*>(curr->getData()))
        {
            cout << "Arrival";
        }
        else if(Prepare *p = dynamic_cast<Prepare*>(curr->getData()))
        {
            cout << "Prepare: ";
        }
        else if(Shipping *s = dynamic_cast<Shipping*>(curr->getData()))
        {
            cout << "Shipping: ";
        }
        
        
        cout << " ID: " << curr->getData()->getID() << " Cost: " << curr->getData()->getPrice() << " Time: " << curr->getData()->getTime() << endl;
        curr = curr->getNext();
    }
    cout << "" << endl;
}

//returns true if queue is empty, false otherwise
bool EventPriorityQueue::isEmpty()
{
    if(front == nullptr)    //check if queue is empty
    {
        return true;
    }
    else
    {
        return false;
    }
}




