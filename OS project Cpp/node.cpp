//
//  node.cpp
//  OS project Cpp
//
//
//  Created by James Galante, Natatie Ayling and Josh Weinick

#include "node.hpp"
#include <iostream>
#include <string>
using namespace std;

Node::Node(int type, int clk, int M, int S, int Q) { //System Configuration
    next = NULL;
    //prev = NULL;
    nType = type;
    clk_time = clk;
    m = M;
    s = S;
    q = Q;
    
}

Node::Node(int type, int clk, int J, int M, int S, int R, int P) { //Job arrival
    next = NULL;
    //prev = NULL;
    nType = type;
    clk_time = clk;
    j = J;
    m = M;
    s = S;
    r = R;
    p = P;
    numDevicesRequested = 0;
    numDevicesUsing = 0;
}

Node::Node(int type, int clk, int J, int D) { //Request for device OR release for device
    next = NULL;
    //prev = NULL;
    nType = type;
    clk_time = clk;
    j = J;
    d = D;
}

Node::Node(int type, int clk) { //display
    next = NULL;
    //prev = NULL;
    nType = type;
    clk_time = clk;
    
}

