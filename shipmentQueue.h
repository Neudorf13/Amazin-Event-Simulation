// CLASS: shipmentQueue.h
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// shipmentQueue.h is the interface that descibres the shipmentQueue class.
// ShipmentQueue is a queue that stores ShippingNodes, and includes pointers to the front and back of the queue.
// ShipmentQueue also includes a constructor, destructor, enqueue for a ShippingNode pointer and dequeue that returns a ShippingNode pointer, isEmpty to check if the queue
// is currently empty and a print method used while testing.
//-----------------------------------------
#pragma once

#include "shippingNode.h"

class ShipmentQueue
{    
    private:        
        ShippingNode *front;
        ShippingNode *back;
    public:
        ShipmentQueue();
        ~ShipmentQueue();
        void enqueue(ShippingNode *newNode);
        ShippingNode* dequeue();
        bool isEmpty();
        void print();
};