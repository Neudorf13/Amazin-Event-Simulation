// CLASS: fileReader.cpp
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// fileReader.cpp is the implementation of the interface fileReader.h.
// fileReader.cpp implements a constructor that recieves a const fileName so that it cannot change during the fileReading process, and initalizes the instance variables
// of inputFile to be this fileName and finishedReading to be false. the getNextLine method will read the next line from the file, retrieve the time, customerType and value
// paramaters from the text and build an Arrival Event to return. If there isn't a nextLine, update the finsihedReading flag to true and return a nullptr.
// getFinsihedReading() is a getter used to check if we have gone through the entire file yet or not.
//-----------------------------------------

#include "fileReader.h"
#include "event.h"
#include "arrival.h"
#include "eventNode.h"
#include <string>
using namespace std;

FileReader::FileReader(const string& fileName) : inputFile(fileName),finishedReading(false)
{
    
}

//parses data from the next line and creates and returns an Arrival Event.
//if file is finsihed reading, updated finishedReading to true and return a nullptr.
Event* FileReader::getNextLine()
{

    string line;
    Event *newArrival = nullptr;
    if(getline(inputFile, line))
    {
        stringstream sst(line);  //stringstream allows us to parse the line token by token (kind of like a Scanner in Java)
		int time = 0;
		string customerType = "";
		int value = 0;
		
		sst >> time;  //extracting the time
		sst >> customerType;  //extracting the customerType
		sst >> value;  //extracting the order value
        newArrival = new Arrival(time, value, customerType);
    }
    else
    {
        finishedReading = true;
    }
    return newArrival;
}

bool FileReader::getFinishedReading()
{
    return finishedReading;
}