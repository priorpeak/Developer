/**
 Alex Prior
 U54686687
 **/

#include "findSingle.h"
#include <iostream>
using namespace std;

int findSingle(int arr[], int arr_size)
{
    int temp;
    for (int i = 0; i < arr_size; i++) // Left comparator
    {
        temp = arr[i];
        for (int j = 0; j < arr_size; j++) // Right comparator
        {
            if (arr[i] != arr[j]) // If the numbers are not equal and the right comparator is at the end of the array, return the left comparator (No duplicates). Otherwise, continue the right comparator loop.
            {
                if (j == arr_size - 1)
                    return temp;
                else
                    continue;
            }
            else if (i == j) // If the indices are equal, continue the right comparator loop, since of course the numbers will be the same at the same index.
            {
                continue;
            }
            else
            {
                if (arr[i] == arr[j]) // If the compared values are duplicates, break the inner loop and increment the left comparator
                {
                    break;
                }
            }
        }
    }
    return temp;
}