//
//  waitQueue.hpp
//  OS project Cpp
//
//
//  Created by James Galante, Natatie Ayling and Josh Weinick


#ifndef waitQueue_hpp
#define waitQueue_hpp

#include <stdio.h>
#include "node.hpp"

class waitQueue {
public:
    Node *first;
    Node *last;
    
    int size;
    waitQueue();
    // ~waitQueue();
    
    
    void addFirst(Node *job);
    void addAtEnd(Node *job);
    
    void moveToRQueue();
    
    void printLL();
    
};



#endif /* waitQueue_hpp */
