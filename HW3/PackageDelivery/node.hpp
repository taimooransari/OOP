#pragma once
#include "truck.hpp"
#include <iostream>
using namespace std;

// BSTNode class 
class BSTNode
{
public:
    Truck val;
    BSTNode *left;
    BSTNode *right;
    BSTNode(){}
    BSTNode(Truck trc)
    {
        val=trc;
        left = NULL;
        right = NULL;
    }
};