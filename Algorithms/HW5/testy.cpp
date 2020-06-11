#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int smallest = i;  // Initialize smalles as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is smaller than root
    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    // If right child is smaller than smallest so far
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    // If smallest is not root
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, smallest);
    }
}

int main()
{
    int arr[20] = {1, 2, 9, 6, 5, 88, 34, 71, 12, 29, 38, 40, 30, 55, 44, 33, 77, 88, 22, 10};
    heapify(arr, 20, 0);
    for (int i = 0; i < 20; i++)
    {
        cout << arr[i] << " , ";
    }
    return 0;
}