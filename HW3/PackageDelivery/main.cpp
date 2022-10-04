#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "node.hpp"
#include <fstream>
using namespace std;

BSTNode *root = NULL; // this is the root of BST

// You have to define the functions below

BSTNode *makeNewNode(Truck trc)
{
    BSTNode *tmp = new BSTNode();
    // tmp->left = NULL;
    // tmp->right = NULL;
    // tmp->val = trc;
    *tmp = BSTNode(trc);
    return tmp;
}

void insertNode(BSTNode *rootNode, Truck trc)
{
    if (rootNode == NULL)
    {
        rootNode = makeNewNode(trc);
    }
    else
    {
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
        // Output the text from the file
        // cout << line<<endl;
        if (tmp == 0)
        {
            driver = line;
        }
        else if (tmp == 1)
        {
            petrol = stod(line);
        }
        else if (tmp == 2)
        {
            regNo = line;
        }
        else if (tmp == 3)
        {
            full = stoi(line);
        }
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

            // {driver, petrol, regNo, full, empty};
            // cout<<"test    "<<tmp_truck.driver<<endl;
            if (root == NULL)
            {
                root = makeNewNode(tmp_truck);
            }
            else
            {
                insertNode(root, tmp_truck);
            }
        }
        tmp++;
    }

    MyReadFile.close();
}

void makeJourney(BSTNode *root)
{
    if (root->left != NULL)
    {
        makeJourney(root->left);
    }
    // cout << root->val.regNo<<endl;
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

void unloadTrucks(BSTNode *root)
{
    if (root->left != NULL)
    {
        unloadTrucks(root->left);
    }

    ofstream MyFile("Trip.txt",ios_base::app);

    // Write to the file
    MyFile << root->val.driver<<"\n";
    MyFile << root->val.petrol<<"\n";
    MyFile << root->val.regNo<<"\n";
    MyFile << root->val.fullMileage<<"\n";
    MyFile << root->val.emptyMileage<<"\n";

    // Close the file
    MyFile.close();

    if (root->right != NULL)
    {
        unloadTrucks(root->right);
    }
}

int main()
{
    // cout<<root->val.regNo;
    loadTrucks();
    // cout << root->val.regNo << endl;
    makeJourney(root);
    unloadTrucks(root);
    return 0;
}
