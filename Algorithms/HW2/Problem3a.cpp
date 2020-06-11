// Alex Prior
// U54686687

#include <iostream>
#include <string.h>

using namespace std;

int kthDigit(int);
string genNext(string);

int kthDigit(int k)
{
    string currentString = "0"; // Start the infinite sequence at 0

    while (k > 0) // k should never decrement less than 0
    {
        // Search currentString
        for (int i = 0; i < currentString.length(); i++)
        {
            k--; // Decrement k as we search through the string

            if (k == 0) // If we reach the index (k) we are searching for, return the value at that index
            {
                return (currentString[i] - '0'); // Return as an integer
            }
        }
        currentString = genNext(currentString); // If we cannot iterate to the given value of k, continue generating the infinite sequence
    }
}

string genNext(string currentString)
{
    bool searching = true;  // Flag to trigger searching through currentString
    char char_match = '\0'; // Var to store char we are counting
    int counter = 1;        // Var to store how many chars of type (char_match) are found
    string outStr = "";     // Initialize empty string before beginning sequencing

    for (int i = 0; i < currentString.length(); i++) // Loop through currentString
    {
        counter = 1;
        searching = true;
        char_match = currentString[i]; // Set char_match to current index we are searching from
        while (searching)
        {
            if (i + 1 < currentString.length()) // Defensive programming so we do not index out of bounds
            {
                if (char_match == currentString[i + 1]) // If char_match matches the index to the right of it, increment counter and i (so we do not count it twice)
                {
                    counter++;
                    i++;
                }
                else
                {
                    searching = false; // If char_match does not match, stop searching
                }
            }
            else
            {
                searching = false; // If we can't look to the right (it would be out of bounds), stop searching
            }
        }
        outStr += (char)('0' + counter); // Add next chars in sequence
        outStr += char_match;
    }
    return outStr; // Return new sequence
}