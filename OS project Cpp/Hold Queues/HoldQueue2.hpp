//
//  HoldQueue2.hpp
//  OS project Cpp
//
//  Created by James Galante on 5/13/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#ifndef HoldQueue2_hpp
#define HoldQueue2_hpp

#include <stdio.h>
#include "node.hpp"

class HoldQueue2 {
    Node *first;
    Node *last;
    
    
public:
    int size;
    HoldQueue2();
    // ~HoldQueue2();
    void addFirst(Node *job);
    void addAtEnd(Node *job);
    void moveToRQueue();
    void printLL();
};


#endif /* HoldQueue2_hpp */
