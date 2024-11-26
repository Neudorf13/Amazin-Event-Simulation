//-----------------------------------------
// NAME		        : Trevor Neudorf
// STUDENT NUMBER	: 7834673
// COURSE		    : COMP 2150
// INSTRUCTOR	    : Franklin Bristow
// ASSIGNMENT	    : assignment #2
// QUESTION	        : question #1
// 
// REMARKS: What is the purpose of this program?
// Application.cpp is the file that includes a main method which conducts a simulation for the company 'Amazin' to measure it's profitabilty based on a variable number of 
// employees. 
// In order to simulate an online marketplace such as 'Amazin', I have included two separte queues. The first one, eventPriorityQueue, stores events of various types.
// The event types include: Arrival events, Prepare events and Shipping events. The instance of eventPriorityQueue makes sure that it is always sorted, front to back,
// by the time of each event, and in the case of a tie, the unique id number is used as a tie breaker so that the lower id number comes first. This is done to ensure
// events are dealt with in the appropriate order to simulate a real ecommerce website that recieves and ships items. Once the instance of eventPriorityQueue is empty,
// this means there are no remaining events to deal with and the simulation comes to an end. As stated previously, we are simulating based on a variable number of employees.
// What happens when a new arrival is recieved but there isn't an available worker, is that arrival event is added to my second queue, shipmentQueue. ShipmentQueue is
// always ordered by priority type customers 'primero' at the front of the queue and standard customers behind them. This means when a new primero is added to the queue,
// it is added behind the last primero order and ahead of the first standard order. When a standard order is added, it is always added to the end of the queue.
// When a shipment is sent out from the eventPriorityQueue, there is now an available worker to begin preparing the next arrival. It then checks if there are any arrivals
// currently waiting inside the shipmentQueue, and if there are, it removes from the front of the shipmentQueue and begins preparing that arrival.
// Appropriate statistics are measured throughout the simulation and outputed as final results once the simulation has concluded.
// The orders arriving are simulated through the use of a text file filed with appropriate arrival events that are read into the program through the use of the fileReader
// class.
//
//-----------------------------------------


#include "event.h"
#include "arrival.h"
#include "prepare.h"
#include "shipping.h"

#include "eventPriorityQueue.h"
#include "eventNode.h"

#include "shipmentQueue.h"
#include "shippingNode.h"

#include "fileReader.h"

#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
    //init priority queues
    EventPriorityQueue priorityQueue = EventPriorityQueue();
    ShipmentQueue shipmentQueue = ShipmentQueue();
    
    cout << setprecision(2) << fixed;   //sets output of doubles to be to 2 decimal points

    //makes sure the appropriate amount of command line arguments are inputed
    if(argc != 3)
	{
		cout <<"USAGE: FileReadingExample.exe filename numAdditionalEmp"<<endl;
		cout <<"where numAdditionalEmp is an integer >= 0."<<endl;
		return 0;
	}

    //recieve command line arguments and print the inputed values
    string filename = argv[1];
	int numAddEmp = stoi(argv[2]);

    cout << "Simulation begins..." << endl;

    //init file reader
    FileReader reader(filename);

    //if file is not empty, read in first Arrival and add it to the priorityQueue
    if(!reader.getFinishedReading())
    {
        Event *newArrival = reader.getNextLine();
        if(newArrival != nullptr)
        {
            newArrival->setArrivalTime(newArrival->getTime());
            EventNode *newNode = new EventNode(newArrival);
            priorityQueue.enqueue(newNode);
        }   
    }

    //tracker variables to be used inside the simulation loop
    int finalTime = 1;
    int workers = 1 + numAddEmp;
    double profit = 0;

    while(!priorityQueue.isEmpty()) //when there are no events left in the priorityQueue, the simulation is complete
    {
        EventNode *temp = priorityQueue.dequeue();  //dequeue next event from the front of the priorityQueue

        if(Arrival *a = dynamic_cast<Arrival*>(temp->getData()))    //if next event is an Arrival
        {
            //announce arrival
            a->print();

            if(workers > 0) //if there is currently an available worker
            {
                //create a Prepare event
                Event *tempPrep = new Prepare(a);

                //create EventNode for the Prepare event
                EventNode *tempNode = new EventNode(tempPrep);

                //enqueue EventNode
                priorityQueue.enqueue(tempNode);

                //delete temporary Arrival event
                delete a;
            }
            else    //if there isn't currently an available worker
            {
                //create a shippingNode
                ShippingNode *shipNode = new ShippingNode(a);

                //add shippingNode to shipmentQueue
                shipmentQueue.enqueue(shipNode);
            }

            //if file is not empty, add another arrival to the queue
            if(!reader.getFinishedReading())
            {
                Event *nextArrival = reader.getNextLine();
                if(nextArrival != nullptr)
                {
                    nextArrival->setArrivalTime(nextArrival->getTime());
                    EventNode *nextEventNode = new EventNode(nextArrival);
                    priorityQueue.enqueue(nextEventNode);
                }
            }
        }
        else if(Prepare *p = dynamic_cast<Prepare*>(temp->getData()))   //if next event is a Prepare
        {
            if(workers > 0) //if theres an available worker
            {
                //announce prep
                p->print();

                //create a Shipping event
                Event *tempShip = new Shipping(p);
                //create an EventNode for the Shipping Event
                EventNode *tempNode = new EventNode(tempShip);
                //add the EventNode to the Priority Queue
                priorityQueue.enqueue(tempNode);
                //decrement available workers
                workers--;
            }
            else
            {
                //incrememnt temp's time (either just add one to it or have another tracker variable for when the next worker is available)
                temp->getData()->setTime(temp->getData()->getTime() + 1);
                //add the Prepare node back to the priority queue since there are no available workers at this time
                priorityQueue.enqueue(temp);
            }

            //delete temporary Prepare event
            delete p;
        }
        else if(Shipping *s = dynamic_cast<Shipping*>(temp->getData())) //if next event is a Shipping
        {

            //calculate number of hours and days it took between arrival and shipping 
            int hoursTaken = s->getTime() - s->getArrivalTime();
            int daysTaken = hoursTaken/8;

            //calculate profit before possible penalities are included
            double grossProfit = (s->getPrice() * .5);

            double penalty = 0;

            //print shipping message
            s->print();

            if(s->getCustomerType() == "primero")
            {
                if(daysTaken > 0)   //if order took longer then promised, calculate and apply penalty
                {
                    penalty = 0.15 * s->getPrice();
                }
                
                //add profit from this order to total profit
                profit += grossProfit - penalty;    

                //print apporpriate message based on if there was a penalty to pay or not
                if(penalty > 0)
                {
                    cout << " ***Penalty paid: $" << penalty << ".";
                }
                cout << "" << endl;
                
            }
            else    //customerType is standard
            {
                if(daysTaken > 2)   //if order took longer then promised, calculate and apply penalty
                {
                    penalty = 0.15 * s->getPrice();
                }

                //add profit from this order to total profit
                profit += grossProfit - penalty;    

                //print apporpriate message based on if there was a penalty to pay or not
                if(penalty > 0)
                {
                    cout << " ***Penalty paid: $" << penalty << ".";
                }
                cout << "" << endl;
            }

            
            workers++;  //increment availble workers

            if(!shipmentQueue.isEmpty())    //if theres an arrival waiting to be prepared
            {                
                //shipmentQueue.dequeue
                ShippingNode *tempShipNode = shipmentQueue.dequeue();
                
                //create a new Prepare event
                Event *newPrep = new Prepare(tempShipNode->getData());
                newPrep->setTime(s->getTime());
                
                //create a new EventNode for the new Prepare event
                EventNode *tempEventNode = new EventNode(newPrep);

                //enqueue new prepare
                priorityQueue.enqueue(tempEventNode);

                //free memory from dequeued ShippingNode
                delete tempShipNode;
            }

            //update the latest time variable to the new current latest time
            finalTime = s->getTime();

            //delete Shipping event
            delete s;
        }

        //delete EventNode
        delete temp;
    }

    //calculate number of days worked based on finalTime of last shipment going out
    int daysWorked;
    if(finalTime % 8 == 0)
    {
        daysWorked = finalTime/8;
    }
    else
    {
        daysWorked = (finalTime/8) + 1;
    }

    //calculate cost of additional employees based on number of days worked, their daily salary of $108 ($13.50 * 8 = $108), number of additional employees,
    //and the fact that every employee gets a diaper every day they work that costs the company an additional $1 each.
    double totalCost = (numAddEmp * daysWorked * 108) + (numAddEmp * daysWorked);
    
    //print final stats of the simulation
    cout << endl;
    cout << "#######################" << endl;
    cout << "The simulation has ended." << endl;
    cout << "The number of additional workers was " << numAddEmp << "." << endl;
    cout << "The total number of work days was " << daysWorked << "." << endl;
    cout << "The cost of the additional workers was $" << totalCost << "." << endl;
    cout << "The total profit before paying workers was $" << profit << "." << endl;
    cout << "The total profit when considering additional workers was $" << profit - totalCost << "." << endl;
    cout << "#######################" << endl;
}