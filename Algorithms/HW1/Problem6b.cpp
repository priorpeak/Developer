/**
 Alex Prior
 U54686687
 **/

#include "sumProductDigit.h"
#include <iostream>

using namespace std;

int sumProductDigit(int a, int b)
{
    int prod = a * b;                  // Multiply the inputs together first
    int runningSum = 0;                // Initialize a running sum variable to zero, for use in the while loop
    while (prod > 0 || runningSum > 9) // In order to run the while loop the first time, we need to set the parameters to if the product is greater than 0 OR if the running sum is greater than 9, since it starts at 0
    {
        if (prod == 0) // If prod gets divided by 10 to the point that it equals zero, we must repeat the while loop using the latest runningSum value
        {
            prod = runningSum; // Set "prod" equal to the latest runningSum value
            runningSum = 0;    // Set runningSum back to zero to start a new iteration of the while loop and a fresh running sum
        }
        runningSum += prod % 10; // Perform modulo on prod to isolate the ones place, then add that value to the running sum
        prod /= 10;              // Divide prod by 10 to repeat the while loop and isolate the next digit
    }
    return runningSum;
}