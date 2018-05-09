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
using namespace std;


class SubmitQueue {
    string wholeFile;
    string currInstruction;
    
public:
    
    void readFile();
    void inputCommand(string line);
    
    void systemConfiguration();
    void JobArrival();
    void requestForDevices();
    void releaseForDevices();
    void display();

    
};

#endif /* submitQueue_hpp */
