//
//  CompleteQueue.hpp
//  OS project Cpp
//
//
//  Created by James Galante, Natatie Ayling and Josh Weinick


#ifndef CompleteQueue_hpp
#define CompleteQueue_hpp

#include <stdio.h>
#include "node.hpp"

class CompleteQueue {
    
public:
    Node *first;
    Node *last;
    
    int size;
    CompleteQueue();
    // ~CompleteQueue();
    
    
    void addFirst(Node *job);
    void addAtEnd(Node *job);
    void printLL();
    
};

#endif /* CompleteQueue_hpp */
