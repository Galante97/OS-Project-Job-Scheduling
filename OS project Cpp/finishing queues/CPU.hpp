//
//  CPU.hpp
//  OS project Cpp
//
//
//  Created by James Galante, Natatie Ayling and Josh Weinick


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
    bool inUse = false; //bankers implementaion (mutex)
    
    CPU();
    // ~CPU();
    
    bool requestDevices();
    void addFirst(Node *job);
    void moveToWaitQueue();
    void moveToRQueue();
    void goToFinishedQueue();
    void printLL();
    
};

#endif /* CPU_hpp */
