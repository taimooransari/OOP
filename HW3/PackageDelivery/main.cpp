#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "node.hpp"
#include <fstream>
using namespace std;

BSTNode *root = NULL; // this is the root of BST

// You have to define the functions below

// Function to create a new node with the truck to be stored as argument
BSTNode *makeNewNode(Truck trc)
{
    BSTNode *tmp = new BSTNode();
    // tmp->left = NULL;
    // tmp->right = NULL;
    // tmp->val = trc;
    *tmp = BSTNode(trc);
    return tmp;
}

// Insert function that stores new nodes in the BST according to the BST Rules. The Registration number is the value that determines where the new node would go.
void insertNode(BSTNode *rootNode, Truck trc)
{
    // if root is null create a node here
    if (rootNode == NULL)
    {
        rootNode = makeNewNode(trc);
    }
    else
    {
        // if root is not null, compare its trucks regNo with new Trucks regNo.
        // The new truck would become the leaf at either the left or right subtree depending on whether if its regNO is lesser than or greater than the root nodes trucks regNo.
        if (rootNode->val.regNo > trc.regNo)
        {
            if (rootNode->left == NULL)
            {

                rootNode->left = makeNewNode(trc);
            }
            else
            {
                insertNode(rootNode->left, trc);
            }
        }
        else
        {
            if (rootNode->right == NULL)
            {

                rootNode->right = makeNewNode(trc);
            }
            else
            {
                insertNode(rootNode->right, trc);
            }
        }
    }
}

// Function to load the trucks data from the Input.txt file
void loadTrucks()
{
    string line;
    string driver, regNo;
    double petrol;
    int full, empty;
    int tmp = 0;

    // Read from the text file
    ifstream MyReadFile("Input.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, line))
    {
        // tmp is a temporary function that is used to determine the line we are reading gives us what value.

        // 0 means its the driver
        if (tmp == 0)
        {
            driver = line;
        }

        // 1 means its the petrol in truck
        else if (tmp == 1)
        {
            petrol = stod(line);
        }

        // 2 means its the Registration Num
        else if (tmp == 2)
        {
            regNo = line;
        }

        // 3 means its the full truck fuel consumption
        else if (tmp == 3)
        {
            full = stoi(line);
        }

        // 4 means its the empty truck fuel consumption
        // when the empty trucks info is read, it means the info needed for an individual truck is complete and now a truck can be created and pased to BST.
        else if (tmp == 4)
        {
            tmp = -1;
            empty = stoi(line);
            Truck tmp_truck;
            tmp_truck.driver = driver;
            tmp_truck.regNo = regNo;
            tmp_truck.petrol = petrol;
            tmp_truck.emptyMileage = empty;
            tmp_truck.fullMileage = full;

            // if root is null, directly store the new truck there by making a node
            if (root == NULL)
            {
                root = makeNewNode(tmp_truck);
            }
            else
            // if root isnt null, use the insert function to make a new leaf node
            {
                insertNode(root, tmp_truck);
            }
        }
        tmp++;
    }
    // close the file after reading is complete
    MyReadFile.close();
}

// Make journey function traverses in inorder and also updates fuel tanks depending whether the truck can afford to make a 60 mile come and go with full and empty.
void makeJourney(BSTNode *root)
{
    if (root->left != NULL)
    {
        makeJourney(root->left);
    }
    double req = (60 / root->val.fullMileage) + (60 / root->val.emptyMileage);
    if (req <= root->val.petrol)
    {
        root->val.petrol -= req;
    }

    if (root->right != NULL)
    {
        makeJourney(root->right);
    }
}

// function to update the trip.txt file with new updated truck values after the journey. Also traversing in inorder.
void unloadTrucks(BSTNode *root)
{
    if (root->left != NULL)
    {
        unloadTrucks(root->left);
    }

    // open txt file for writing/appending
    ofstream MyFile("Trip.txt", ios_base::app);

    // Write to the file
    MyFile << root->val.driver << "\n";
    MyFile << root->val.petrol << "\n";
    MyFile << root->val.regNo << "\n";
    MyFile << root->val.fullMileage << "\n";
    MyFile << root->val.emptyMileage << "\n";

    // Close the file
    MyFile.close();

    if (root->right != NULL)
    {
        unloadTrucks(root->right);
    }
}

int main()
{
    // start the function by loading file
    loadTrucks();
    // make the journey
    makeJourney(root);
    // update trip.txt after the journey is complete
    unloadTrucks(root);
    return 0;
}
