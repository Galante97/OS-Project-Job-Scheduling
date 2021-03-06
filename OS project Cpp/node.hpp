//
//  node.hpp
//  OS project Cpp
//
//
//  Created by James Galante, Natatie Ayling and Josh Weinick


#ifndef node_hpp
#define node_hpp

#include <iostream>
#include <string>
using namespace std;

class Node {
    friend class CompleteQueue;
    friend class SubmitQueue;
    friend class HoldQueue1;
    friend class HoldQueue2;
    friend class readyQueue;
    friend class CPU;
    friend class waitQueue;
    friend class main;
    
    
    Node *next;
    int count;
    
public:
    int clk_time;
    int m;
    int s;
    int q;
    int d;
    int p;
    int r;
    int j;
    int nType;
    int numDevicesRequested;
    int numDevicesUsing;
    
    Node(int type, int clk, int M, int S, int Q); //system Configuration
    Node(int type, int clk, int J, int M, int S, int R, int P); //Job arrival
    Node(int type, int clk, int J, int D); //Request for device OR release for device
    Node(int type, int clk); //display
    Node();
    
};

#endif /* NODE_HPP_ */
