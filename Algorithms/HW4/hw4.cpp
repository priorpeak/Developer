// Alex Prior
// U54686687

#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include "hw4.h"

using namespace std;

// (a)
int unsorted_mode(std::vector<int> v)
{
    vector<int> count(v.size());
    // Initialize variables
    int mode = 0;
    int max = 0;
    int num = 0;
    int counter = 0;
    int index = 0;
    num = v[index];
    // Set dummy variable num equal to the first value in the given vector
    while (index < v.size()) // While we are still indexing inside the given vector:
    {
        counter = 0;
        // Reset counter (for counting repeat values) to zero at the beginning of every loop
        for (int i = 0; i < v.size(); i++) // Loop through the given vector
        {
            if (num == v[i]) // If the value at the given index matches the value in the dummy variable:
            {
                counter++; // Increment the counter
            }
        }

        count[index] = counter; // Store value in counter in the count vector
        index++;                // Increment index for the next iteration
        num = v[index];         // Set num equal to the value in the next index of the given vector, setting up for the next iteration
    }

    max = count[0];                        // Initialize the max variable to the value in the first index of the counter vector
    mode = v[0];                           // Initialize the mode variable to the first index of the given vector
    for (int j = 1; j < count.size(); j++) // Loop through the counter vector
    {
        if (count[j] > max) // If the value in the current index of the counter vector is larger than the value in max:
        {
            max = count[j]; // Reset max to the value in the counter vector
            mode = v[j];    // Reset the mode to the value at the same index in the given vector
        }
    }

    return mode; // Return the mode
}

// (b)
int sorted_mode(std::vector<int> v)
{
    int maxCounter = 0; // Initialize variables
    int counter = 0;
    int num = 0;
    int mode = 0;
    num = v[0];
    for (int i = 0; i < v.size(); i++) // Loop through given vector
    {
        if (v[i] == num) // If value at current index is equal to previous num:
        {
            counter++; // Increment counter
        }
        else
        {
            if (counter > maxCounter) // If current counter value is greater than maxCounter value:
            {
                maxCounter = counter; // Reset maxCounter value
                mode = v[i - 1];      // Set mode variable
            }
            counter = 1; // Reset counter
            num = v[i];  // Change num value for next iteration
        }
    }
    return mode;
}

// (c)
std::pair<int, int> unsorted_closest_integers(std::vector<int> v)
{
    int minDiff = -1; // Initialize variables
    int num1 = 0;
    int num2 = 0;
    int key = 0;
    int k = 0;

    for (int i = 1; i < v.size(); i++) // Insertion sort
    {
        key = v[i];
        k = i - 1;
        while (k >= 0 && v[k] > key)
        {
            v[k + 1] = v[k];
            k--;
        }
        v[k + 1] = key;
    }

    for (int i = 0; i < v.size() - 1; i++) // Loop through given vector
    {
        {
            if (v[i + 1] - v[i] < minDiff || minDiff == -1) // If difference between two indices are less than last value of minDiff:
            {
                minDiff = v[i + 1] - v[i]; // Reset minDiff
                num1 = v[i];               // Reset num1 for next iteration
                num2 = v[i + 1];           // Reset num2 for next iteration
            }
        }
    }
    return std::make_pair(num1, num2);
}

// (d)
std::pair<std::pair<int, int>, std::pair<int, int>>
unsorted_closest_coordinates(std::vector<std::pair<int, int>> v)
{
    int minDiff = -1; // Initialize variables and vectors
    pair<int, int> pair1 = make_pair(0, 0);
    pair<int, int> pair2 = make_pair(0, 0);

    for (int i = 0; i < v.size() - 1; i++) // Loop through given vector
    {
        for (int j = i + 1; j < v.size(); j++) // Loop vector starting from index to the right of outer loop
        {
            if (sqrt(pow((v[i].first - v[j].first), 2) + pow((v[i].second - v[j].second), 2)) < minDiff || minDiff == -1) // If euclidean distance is less than previous:
            {
                minDiff = sqrt(pow((v[i].first - v[j].first), 2) + pow((v[i].second - v[j].second), 2)); // Reset euclidean distance var
                pair1.first = v[i].first;                                                                // Reset vars for next iteration
                pair1.second = v[i].second;
                pair2.first = v[j].first;
                pair2.second = v[j].second;
            }
        }
    }
    return std::make_pair(pair1, pair2);
}

// (e)
void flip_sort(std::vector<int> &v)
{
    int size = v.size(); // Initialize variables
    int i = 0;
    for (size; size > 1; size--) // Loop through given vector in reverse
    {
        int maxIndex = max_element(v.begin(), v.end() - i) - v.begin(); // Find index of maximum element

        if (maxIndex != size - 1) // If maximum element is not already at the end:
        {
            flip(v, 0, maxIndex); // Flip it to the beginning
            flip(v, 0, size - 1); // Flip the whole vector so it is at the end
        }
        i++; // Increment i for next iteration
    }
}

// (f)
void peak_valley_sort(std::vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++) // Loop through given vector
    {
        if (i % 2 == 0) // zigzag sort
        {
            if (v.at(i) > v.at(i + 1))
                swap(v.at(i), v.at(i + 1));
        }
        else
        {
            if (v.at(i) <= v.at(i + 1))
                swap(v.at(i), v.at(i + 1));
        }
    }
}

// (g)
void length_alpha_sort(std::vector<std::string> &v)
{
    int n = v.size(); // Initialize vars for insertion sort
    int key, j;
    string prev;

    for (int i = 1; i < n; i++) // Insertion sort
    {
        key = v[i].length();
        prev = v[i];

        j = i - 1;
        while (j >= 0 && v[j].length() > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = prev;
    }

    int index = 0; // Initialize vars and vector
    int prevIndex = 0;
    vector<pair<int, int>> sameLengths;
    while (index < v.size()) // While we have not reached the end of the vector:
    {
        if (v[index].length() != v[index + 1].length()) // If the next index length does not equal the previous index length:
        {
            sameLengths.push_back(make_pair(prevIndex, index)); // Add these two indices as a pair to the sameLengths vector
            prevIndex = index + 1;                              // Increment prevIndex for next iteration
        }
        index++; // Increment index for next iteration
    }

    for (int i = 0; i < sameLengths.size(); i++) // Loop through the sameLengths vector
    {
        for (int j = sameLengths[i].first; j <= sameLengths[i].second; j++) // Loop from beginning to end of pair at given index of sameLengths vector
        {
            for (int k = j + 1; k <= sameLengths[i].second; k++) // Loop through indices to the right of j indexx
            {
                index = 0;                                                          // Reset index for start of every iteration
                while (v[j][index] == v[k][index] && index < sameLengths[i].second) // While the chars inside the string are equal, and index is still within the given bounds:
                {
                    index++; // Increment index
                }
                if (v[j][index] > v[k][index]) // If the ASCII value at index j is greater than the ASCII value at index k:
                {
                    swap(v[j], v[k]); // Swap them
                }
            }
        }
    }
}