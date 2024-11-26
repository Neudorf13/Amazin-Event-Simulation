// CLASS: fileReader.h.h
//
// Author: Trevor Neudorf, 7834673
//
// REMARKS: What is the purpose of this class? 
//
// fileReader.h is the interface that describes the class FileReader.
// FileReader has 2 private instance varibles. inputFile which will be used for file reading and a boolean to mark whether or not the entire file has been read yet.
// Included as well is: a constructor that recieves a constant string fileName and will initalize the file reader for the given fileName, getNextLine which will return
// a pointer to an Event that was created by parsing the information from the next line in the file, as well as a getter for finsihedReading.
//-----------------------------------------
#pragma once

#include "event.h"
#include <string>
#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <iostream>

using namespace std;

class FileReader
{
    private:
        ifstream inputFile;
        bool finishedReading;
    public:
        FileReader(const string& fileName);
        Event *getNextLine();
        bool getFinishedReading();
};