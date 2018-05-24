//
//  waitQueue.hpp
//  OS project Cpp
//
//  Created by James Galante on 5/15/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

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
