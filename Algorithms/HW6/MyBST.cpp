// Alex Prior
// U54686687

//  MyBST.cpp
//  bst_transform
//

#include "MyBST.h"
#include <iostream>

using namespace std;

/**
 * Computes how to transform this MyBST into the target MyBST using rotations.
 * Returns a vector of rotations indicating which rotations around which nodes
 * must be performed to transform this into the target.
 *
 * IMPORTANT: We want to transform T1 into T2 so the call should look like
 * rotations = t1.transform(t2)
 */

vector<Rotation> MyBST::transform(MyBST target)
{
    Node *currentNode = this->root; // Initialize currentNode pointer to root of BST
    vector<Rotation> rots;          // Initialize vector to store keys and rotations of start vector
    vector<int> targetRots;         // Initialize vector to store keys and rotations of target vector

    while (currentNode) // While currentNode exists:
    {
        while (currentNode->left) // While there are left children:
        {
            rots.push_back(Rotation(currentNode->key, ZIG)); // Store the current key and rotation type
            this->rotateRight(currentNode);                  // Rotate BST to the right
        }
        currentNode = currentNode->right; // Reassign currentNode to the right child and repeat
    }

    Node *targetRoot = target.root; // Initialize another Node pointer at the root of the target BST
    while (targetRoot)              // While targetRoot exists:
    {
        while (targetRoot->left) // While there are left children:
        {
            targetRots.push_back(targetRoot->key); // Store the current key
            this->rotateRight(targetRoot);         // Rotate BST to the right
        }
        targetRoot = targetRoot->right; // Reassign targetRoot to the right child and repeat
    }

    for (int i = targetRots.size() - 1; i >= 0; i--) // Traverse through the targetRots vector backwards to reverse the rotations by key
    {
        currentNode = this->root;                            // Start searching from the top of the BST
        currentNode = searchBST(currentNode, targetRots[i]); // Recursively search for the parent node of the node with the specified key
        rots.push_back(Rotation(currentNode->key, ZAG));     // Store the key and rotation type
        this->rotateLeft(currentNode);                       // Rotate left
    }
    // After this for loop finishes the start tree will match the original target tree

    return rots;
}

void MyBST::rotateRight(Node *Q)
{
    if (!Q || !Q->left)
        return;

    int temp = Q->key;
    Q->key = Q->left->key;
    Q->left->key = temp;

    Node *left = Q->left;
    Q->left = left->left;
    left->left = left->right;
    left->right = Q->right;
    Q->right = left;
    return;

    // Node *P = Q->left;
    // Q->left = P->right;
    // P->right = Q;
    // return P;
}

void MyBST::rotateLeft(Node *P)
{
    if (!P || !P->right)
        return;

    int temp = P->key;
    P->key = P->right->key;
    P->right->key = temp;

    Node *left = P->right;
    P->right = left->right;
    left->right = left->left;
    left->left = P->left;
    P->left = left;
    return;

    // Node *Q = P->right;
    // P->right = Q->left;
    // Q->left = P;
    // return Q;
}

// Custom search function
Node *MyBST::searchBST(Node *root, int key)
{
    if (root->left && root->left->key == key) // If the left child exists and is equal to key, return the parent
        return root;
    else if (root->right && root->right->key == key) // If the right child exists and is equal to the key, return the parent
        return root;
    else if (root->key > key) // Otherwise, if the parent key is greater than the given key, continue searching down the left branch
        return searchBST(root->left, key);
    else // Otherwise continue searching down the right branch
        return searchBST(root->right, key);
}