//
//  node.hpp
//  OS project Cpp
//
//  Created by James Galante on 5/9/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

#include <iostream>
#include <string>
using namespace std;

class Node {
    friend class SubmitQueue;
    friend class HoldQueue1;
    friend class HoldQueue2;
    friend class readyQueue;
    friend class CPU;
    friend class waitQueue;
    
    Node *next;
    //Node *prev;
    int count;
    
    int nType;
    int clk_time;
    int m;
    int s;
    int q;
    int j;
    int r;
    int d;
    int p;
    
    bool jobGotDevices = false; //only applies to jobs
    
    
   
public:
    Node(int type, int clk, int M, int S, int Q); //system Configuration
    Node(int type, int clk, int J, int M, int S, int R, int P); //Job arrival
    Node(int type, int clk, int J, int D); //Request for device OR release for device
    Node(int type, int clk); //display
    Node();

};


#endif /* NODE_HPP_ */
