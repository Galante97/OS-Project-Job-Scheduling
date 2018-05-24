//
//  HoldQueue1.hpp
//  OS project Cpp
//
//
//  Created by James Galante, Natatie Ayling and Josh Weinick


#ifndef HoldQueue1_hpp
#define HoldQueue1_hpp

#include <stdio.h>
#include "node.hpp"

//SJF
class HoldQueue1 {
    
    
public:
    Node *first;
    Node *last;
    
    int size;
    HoldQueue1();
    // ~HoldQueue1();
    void addFirst(Node *job);
    void addInOrder(Node *job);
    void moveToRQueue();
    void printLL();
};


#endif /* HoldQueue1_hpp */
