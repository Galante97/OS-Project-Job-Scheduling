//
//  readyQueue.hpp
//  OS project Cpp
//
//  Created by James Galante on 5/15/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#ifndef readyQueue_hpp
#define readyQueue_hpp

#include <stdio.h>
#include "node.hpp"

class readyQueue {
    Node *first;
    Node *last;
    
public:
    int size;
    bool Adding = false;
    
    
    readyQueue();
    // ~HoldQueue1();
    
    void addFirst(Node *job);
    void addAtEnd(Node *job);
    void moveToCPU();
    
    void printLL();
    
   // int *getContentsForJSON();
    
};



#endif /* readyQueue_hpp */
