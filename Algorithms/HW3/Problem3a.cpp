// Alex Prior
// U54686687

#include <iostream>
#include <vector>

using namespace std;

void zigzagSort(vector<int> &);

void zigzagSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++) // Loop through the whole vector
    {
        if (i % 2 == 0) // Switch code every other iteration
        {
            if (nums.at(i) > nums.at(i + 1)) // If left index is greater than right index, swap them
            {
                swap(nums.at(i), nums.at(i + 1));
            }
        }
        else
        {
            if (nums.at(i) < nums.at(i + 1)) // If left index is less than right index, swap them
            {
                swap(nums.at(i), nums.at(i + 1));
            }
        }
    }
}