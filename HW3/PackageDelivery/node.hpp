#pragma once
#include "truck.hpp"
#include <iostream>
using namespace std;
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