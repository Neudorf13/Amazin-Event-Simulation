// CLASS: shipmentQueue.cpp
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// shipmentQueue.cpp is the implementation of the interface shipmentQueue.h.
// shipmentQueue.cpp defines a constructor that takes no parameters and initalizes the queue to be empty, a destructor that, if the the queue isn't empty when it is destroyed,
// will go through the entire queue and delete all the remaining ShippingNodes, enqueue recieves a pointer to a ShippingNode, checks whether the customerType of the event 
// stored in the node is a primero member or not, if it is, adds the node to the queue right after the last primero node, otherwise if not a primero, simply adds it to the
// end of the queue, dequeue removes the first node in the queue and returns it while setting the front pointer to the next node in the queue, if queue is empty, returns
// nullptr, isEmpty returns true if the queue is empty and false otherwise.
// Also has a print method that was used for testing purposes.
//-----------------------------------------

#include "shipmentQueue.h"
#include "eventNode.h"

#include <iostream>
using namespace std;

ShipmentQueue::ShipmentQueue()
{
    front = back = nullptr;
}

//if queue is not empty when deleted, go through and delete all nodes within the queue
ShipmentQueue::~ShipmentQueue()
{
    if(front != nullptr)
    {
        ShippingNode *prev = nullptr;
        ShippingNode *curr = front;
        while(curr != nullptr)
        {
            prev = curr;
            curr=curr->getNext();
            delete prev;
        }
    }
    front = back = nullptr;
}

//add a new ShipNode to the queuue, if newNodes event is a primero customerType, add to the queue behind the last primero node, othewise add to the end of the queue
void ShipmentQueue::enqueue(ShippingNode *newNode)
{
    bool member = false;
    if(newNode->getData()->getCustomerType() == "primero")
    {
        member = true;
    }

    if(front == nullptr)    //if queue is empty
    {
        front = back = newNode;
    }
    else if(member)    
    {
        ShippingNode *prev = nullptr;
        ShippingNode *curr = front;
        while(curr != nullptr && curr->getData()->getCustomerType() == "primero")
        {
            prev = curr;
            curr = curr->getNext();
        }
        //curr is either the first non-primero or nullptr when this loop ends

        if(curr == nullptr) //all orders in queue are currently primero
        {
            back->setNext(newNode);
            back = newNode;
        }
        else if(prev == nullptr) //no orders in queue are currently primero
        {
            newNode->setNext(front);
            front = newNode;
        }
        else    //somewhere in the middle of the queue
        {
            prev->setNext(newNode);
            newNode->setNext(curr);
        }
    }
    else    //non-member = add to end of queue
    {
        back->setNext(newNode);
        back = newNode;
    }   
}

//remove first Node in queue and returns
ShippingNode* ShipmentQueue::dequeue()
{
    ShippingNode *removed = nullptr;
    if(front != nullptr)
    {
        removed = front;
        front = front->getNext(); 
    }
    return removed;
}

//returns true if queue is empty, false otherwise
bool ShipmentQueue::isEmpty()
{
    if(front == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//used for testing
void ShipmentQueue::print()
{
    ShippingNode *curr = front;
    while(curr != nullptr)
    {
        cout << curr->getData()->getID() << " " << endl;
        curr =curr->getNext();
    }
    cout << " " << endl;
}