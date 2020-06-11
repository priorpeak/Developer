// Alex Prior
// U54686687

#include <vector>
#include <iostream>

using namespace std;

int findKthSmallest(vector<int>, vector<int>, int);

int findKthSmallest(vector<int> A, vector<int> B, int k)
{
    int smol, num1, num2 = 0; // Placeholder variables for comparing two numbers and holding the smaller of the two

    while (k > 0) // While k is greater than zero, continue working down the vector and comparing numbers
    {
        if (A.size() == 0) // Defensive programming, if all the elements in vector A are deleted, you should only compare elements in vector B
        {
            smol = B.back(); // Set the next smallest number equal to the last element in vector B
            B.pop_back();    // After setting this element equal to the placeholder variable, delete it from the vector
        }
        else if (B.size() == 0) // Defensive programming, if all the elements in vector B are deleted, you should only compare elements in vector A
        {
            smol = A.back(); // Set the next smallest number equal to the last element in vector A
            A.pop_back();    // After setting this element equal to the placeholder variable, delete it from the vector
        }
        else // If both vector A and B exist, proceed below
        {
            num1 = A.back(); // Set the first placeholder variable equal to the last element of vector A
            num2 = B.back(); // Set the second placeholder variable equal to the last element of vector B
            if (num1 < num2) // If the element in vector A is smaller than the element in vector B, set the smallest value placeholder equal to the element in vector A
            {
                smol = num1;
                A.pop_back(); // Delete the last element in vector A after setting it equal to the placeholder variable "smol"
            }
            else // Otherwise, set the smallest value placeholder equal to the element in vector B
            {
                smol = num2;
                B.pop_back(); // Delete the last element in vector B after setting it equal to the placeholder variable "smol"
            }
        }
        k--; // Decrement k after each loop until the kth smallest number is found
    }
    return smol; // After the kth loop, return the value of smol
}