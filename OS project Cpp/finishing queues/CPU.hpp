//
//  CPU.hpp
//  OS project Cpp
//
//  Created by James Galante on 5/15/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#ifndef CPU_hpp
#define CPU_hpp

#include <stdio.h>
#include "node.hpp"

class CPU {
    friend class readyQueue;
    friend class main;
    
public:
    Node *first;
    Node *last;
    int size;
    bool inUse = false;
    
    CPU();
    // ~CPU();
    
    
    void addFirst(Node *job);
    void addAtEnd(Node *job);
    void processJob();
    void moveToWaitQueue();
    void goToFinishedQueue();
    void printLL();
    
};

#endif /* CPU_hpp */
