//
//  readyQueue.hpp
//  OS project Cpp
//
//
//  Created by James Galante, Natatie Ayling and Josh Weinick

#ifndef readyQueue_hpp
#define readyQueue_hpp

#include <stdio.h>
#include "node.hpp"

class readyQueue {
   
    
public:
    Node *first;
    Node *last;
    
    int size;
    bool Adding = false; //Bankers (mutex)
    
    
    readyQueue();
    // ~HoldQueue1();
    
    void addFirst(Node *job);
    void addAtEnd(Node *job);
    void moveToCPU();
    
    void printLL();
    
    // int *getContentsForJSON();
    
};



#endif /* readyQueue_hpp */
