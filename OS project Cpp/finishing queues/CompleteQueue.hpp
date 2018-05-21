//
//  CompleteQueue.hpp
//  OS project Cpp
//
//  Created by James Galante on 5/15/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#ifndef CompleteQueue_hpp
#define CompleteQueue_hpp

#include <stdio.h>
#include "node.hpp"

//SJF
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
