//
//  HoldQueue1.hpp
//  OS project Cpp
//
//  Created by James Galante on 5/13/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#ifndef HoldQueue1_hpp
#define HoldQueue1_hpp

#include <stdio.h>
#include "node.hpp"

//SJF
class HoldQueue1 {
    Node *first;
    Node *last;
    

public:
    int size;
    HoldQueue1();
   // ~HoldQueue1();
    
    
    void addFirst(Node *job);
    void addAtEnd(Node *job);
    void moveToRQueue(Node *job);

    void printLL();

};

#endif /* HoldQueue1_hpp */
