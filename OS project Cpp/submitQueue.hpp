//
//  submitQueue.hpp
//  OS project Cpp
//
//  Created by James Galante on 5/8/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#ifndef submitQueue_hpp
#define submitQueue_hpp

#include <stdio.h>
#include <string>
#include <cstring>
#include "node.hpp"

using namespace std;


class SubmitQueue {
    string wholeFile;
    string currInstruction;
    
public:
    
    void inputCommand(string line);
    bool checkCLKTime(string line);
    void systemConfiguration(string line);
    void JobArrival(string line);
    void display(string line);
    
    //void printFiles();
    
};

#endif /* submitQueue_hpp */
