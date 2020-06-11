// Alex Prior
// U54686687

#include <string>
#include <iostream>
#include "trie.h"

using namespace std;

void Trie::insert(string key, int val)
{
    map_size++;                         // Increment map size whenever we create a new child
    int index;                          // Index variable to keep track of node traversal
    TrieNode *currentNode = this->root; // Initialize a TrieNode pointer at root to be used to traverse trie

    for (int i = 0; i < key.length(); i++) // Traverse the trie by indexing the key
    {
        index = key[i] - 'a'; // Convert the key char to its ASCII value and store in index

        if (!currentNode->children[index]) // If the child we need does not exist already, create it
        {
            currentNode->children[index] = new TrieNode();
            tree_size++;
        }

        currentNode = currentNode->children[index]; // Reassign the TrieNode pointer to the child for the next iteration
    }
    currentNode->val = val; // When we are done traversing the trie, populate the current node with the specified value
}

int Trie::search(string key)
{
    int index;                          // Index variable to keep track of node traversal
    TrieNode *currentNode = this->root; // Intialize a TrieNode pointer at root to be used to traverse trie

    for (int i = 0; i < key.length(); i++) // Traverse the trie by indexing the key
    {
        index = key[i] - 'a'; // Convert the key char to its ASCII value and store in index

        if (!currentNode->children[index]) // If the child we need does not exist already, return 0
            return 0;

        currentNode = currentNode->children[index]; // Reassign the TrieNode pointer to the child for the next iteration
    }
    return currentNode->val; // When we are done traversing the trie, return the value at the current node
}

void Trie::remove(string key)
{
    int numEmptyChildren = 0;           // Initialize var to store number of empty children a given node has
    int index = 0;                      // Initialize an index variable to traverse the trie
    TrieNode *currentNode = this->root; // Initialize a TrieNode pointer to traverse the trie

    for (int i = 0; i < key.length() - 1; i++) // Traverse the trie until we arrive one node before the target node
    {
        index = key[i] - 'a'; // Convert key char to ASCII for traversal

        currentNode = currentNode->children[index]; // Reset the node to its child to continue traversing
    }

    for (int i = 0; i < 26; i++) // Loop through the size of the alphabet to see if any children exist
    {
        if (currentNode->children[key[key.length() - 1] - 'a']->children[i] == NULL)
        {
            numEmptyChildren++; // If there is not a child at this index, increment numEmptyChildren
        }
    }

    if (numEmptyChildren == 26) // If all children are empty, delete the node and decrement map_size and tree_size
    {
        delete currentNode->children[key[key.length() - 1] - 'a'];
        currentNode->children[key[key.length() - 1] - 'a'] = NULL;
        map_size--;
        tree_size--;
    }
    else // Otherwise, set the target node's value to 0 and only decrement map_size
    {
        currentNode = currentNode->children[key[key.length() - 1] - 'a'];
        currentNode->val = 0;
        map_size--;
    }
}
