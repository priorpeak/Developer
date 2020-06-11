// Alex Prior
// U54686687

#include <vector>
#include <iostream>
#include "hw5.h"

using namespace std;

// (a)

int heapDelete(vector<int> &, vector<int> &);       // Function prototype
void heapInsert(vector<int> &, int, vector<int> &); // Function prototype

void heapInsert(vector<int> &vec, int num, vector<int> &indexHeap) // Function to insert nodes into temp_heap
{
    vec.push_back(num);     // Insert num at back of temp heap
    int i = vec.size() - 1; // Stores index of target num

    while (true) // Loop repeatedly until return condition is met
    {
        if (vec.size() - 1 == 0)
            return;
        if (i % 2 == 0) // If target num is in a right branch:
        {
            if (vec[(i - 2) / 2] < vec[i] || vec[(i - 2) / 2] >= vec.size()) // If the parent is already less than target num or if the target num is root:
                return;                                                      // End function
            else                                                             // Otherwise:
            {
                swap(vec[(i - 2) / 2], vec[i]); // Swap parent and child
                i = (i - 2) / 2;                // Reset index to be where target num is (Now parent)
            }
        }
        else // If target num is in left branch:
        {
            if (vec[(i - 1) / 2] < vec[i] || vec[(i - 1) / 2] >= vec.size()) // If the parent is already less than target num or if the target num is root:
                return;                                                      // End function
            else                                                             // Otherwise:
            {
                swap(vec[(i - 1) / 2], vec[i]); // Swap parent and child
                i = (i - 1) / 2;                // Reset index to be where target num is (Now parent)
            }
        }
    }
}

int heapDelete(vector<int> &vec, vector<int> &indexHeap) // Function to delete and re-sort nodes in temp_heap
{
    int size = vec.size();       // Initialize size variable
    int smallest = 0;            // Dummy variable for storing smallest node
    int smallestIndex = 0;       // Dummy variable for storing index of smallest node
    int newIndex = indexHeap[0]; // Dummy variable for storing new index of node who's children will be inserted next
    int index = 0;               // Dummy variable for beginning loop at top of temp_vec

    vec[0] = vec[size - 1]; // Set first element of temp_vec equal to last element
    vec.pop_back();         // Delete the last element

    indexHeap[0] = indexHeap[size - 1]; // Set first element of indexHeap equal to last element
    indexHeap.pop_back();               // Delete the last element

    // Check children for smallest node
    while (vec[index * 2 + 1] < vec[index] && vec[index * 2 + 2] < vec[index]) // Loop through while both children are not smaller than the parent
    {
        if (index * 2 + 1 >= vec.size()) // If the leftmost child does not exist, the function is done
            return newIndex;
        else if (index * 2 + 2 >= vec.size()) // If the right child does not exist, only check the left child against the parent for the smaller value
        {
            if (vec[index * 2 + 1] < vec[index]) // If the left child is smaller:
            {
                swap(vec[index], vec[index * 2 + 1]);             // Swap them
                swap(indexHeap[index], indexHeap[index * 2 + 1]); // Also swap indices to keep track of where we are in the min_heap
                index = index * 2 + 1;                            // Reset index to the left child
            }
            return newIndex; // Return newIndex
        }
        else // Otherwise:
        {
            smallest = vec[index * 2 + 1]; // Set smallest to left child to start
            smallestIndex = index * 2 + 1; // Set smallestIndex to index of left child

            if (vec[index * 2 + 2] < smallest) // If right child is smaller than smallest:
            {
                smallest = vec[index * 2 + 2]; // Reset smallest to value of right child
                smallestIndex = index * 2 + 2; // Reset smallestIndex to index of right child
            }
            if (smallest < vec[index]) // If smallest is less than parent:
            {
                swap(vec[index], vec[smallestIndex]);             // Swap them
                swap(indexHeap[index], indexHeap[index * 2 + 2]); // Also swap indices to keep track of where we are in the min_heap
                index = index * 2 + 2;                            // Reset index to the right child
            }
        }
    }
    return newIndex; // Return the new index for the next set of comparisons
}

std::vector<int> findMinK(const int k, const std::vector<int> &min_heap)
{
    vector<int> answer;                    // Vector to contain k smallest numbers
    vector<int> temp_heap = {min_heap[0]}; // a mini min-heap
    vector<int> indexHeap;                 // another mini min-heap to keep track of the original indices of nodes we populate temp_heap with

    int index = 0;                 // Start at the top of the tree
    answer.push_back(min_heap[0]); // We know the root of the given min_heap will be the smallest value
    indexHeap.push_back(index);    // We know the index of the smallest value will be 0
    while (answer.size() < k)      // While answer vector does not contain k smallest numbers, continue looping:
    {
        index = heapDelete(temp_heap, indexHeap); // Reset index to the new root of the indexHeap
        if (index * 2 + 1 < min_heap.size())      // If a left child exists in min_heap:
        {
            indexHeap.push_back(index * 2 + 1);                        // Put the index of the left child into indexHeap
            heapInsert(temp_heap, min_heap[index * 2 + 1], indexHeap); // Insert new nodes into temp_heap
        }
        if (index * 2 + 2 < min_heap.size()) // If a right child also exists in min_heap:
        {
            indexHeap.push_back(index * 2 + 2);                        // Put the index of the right child into indexHeap
            heapInsert(temp_heap, min_heap[index * 2 + 2], indexHeap); // Insert new nodes into temp_heap
        }
        answer.push_back(temp_heap[0]); // Put the root of temp_heap into the answer vector (This is the next smallest value)
    }
    return answer; // Return the answer vector
}

// (b)

class SillyHashFun : public HashFun
{
    unsigned int operator()(const std::string &key)
    {
        // Here's my silly hash function that always returns 0.
        // You should make some good hash functions and not use this one.
        // This is just an example of how to inherit the HashFun class.
        return 0;
    }
};

class GoodHashFun_0 : public HashFun
{
    unsigned int operator()(const std::string &key)
    {
        // You've seen my silly hash function above.
        // Your good hash function should go here!
        unsigned int hash = 1315423911;
        unsigned int i = 0;

        for (i = 0; i < key.length(); ++i)
        {
            hash ^= ((hash << 5) + (key[i]) + (hash >> 2));
        }

        return hash;
    }
};

class GoodHashFun_1 : public HashFun
{
    unsigned int operator()(const string &key)
    {
        unsigned int seed = 131; /* 31 131 1313 13131 131313 etc.. */
        unsigned int hash = 0;
        unsigned int i = 0;
        for (i = 0; i < key.length(); ++i)
        {
            hash = (hash * seed) + (key[i]);
        }
        return hash;
    }
};

// ...
// You can make as many hash functions as you want!
// ...

void BloomFilter::add_hash_funs()
{
    // You will need to implement this function, it is responsible
    // for adding your custom hash functions to your bloom filter.

    // Here's an example where I add two hash functions.
    // You will need to add at least one hash function.
    GoodHashFun_0 *h1 = new GoodHashFun_0();
    GoodHashFun_1 *h2 = new GoodHashFun_1();
    this->hash_funs.push_back(h1);
    this->hash_funs.push_back(h2);
}

void BloomFilter::insert(const std::string &key)
{
    // You will need to implement this function, it is responsible
    // for inserting key into the bloom filter.

    unsigned int hash_result;

    for (int i = 0; i < this->hash_funs.size(); i++) // Loop through the hash_funs vector to call hash functions, store in filter
    {
        hash_result = this->call_hash(i, key);
        (this->filter)[hash_result % 330] = 1;
    }
}

bool BloomFilter::member(const std::string &key)
{
    // This function should report true if key is potentially in the bloom filter.
    // It should only return false if you know for sure that key is not in the bloom filter.

    //
    // your code here ...
    //

    for (int i = 0; i < this->hash_funs.size(); i++) // Loop through hash_funs vector to call hash functions, check for zeros in filter
    {
        if (this->filter[(this->call_hash(i, key) % 330)] == 0)
            return false;
    }
    return true;
}