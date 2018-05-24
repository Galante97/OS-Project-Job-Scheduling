//
//  HoldQueue2.hpp
//  OS project Cpp
//
//
//  Created by James Galante, Natatie Ayling and Josh Weinick

#ifndef HoldQueue2_hpp
#define HoldQueue2_hpp

#include <stdio.h>
#include "node.hpp"

class HoldQueue2 {

public:
    Node *first;
    Node *last;
    int size;
    HoldQueue2();
    // ~HoldQueue2();
    void addFirst(Node *job);
    void addAtEnd(Node *job);
    void moveToRQueue();
    void printLL();
};


#endif /* HoldQueue2_hpp */
