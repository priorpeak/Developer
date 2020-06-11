#include <iostream>
#include "hw4.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "Hello, World!" << std::endl;
    vector<int> unsorted = {-2, -299, 4, -299, 50, -29926, 27, 85, -299, 8, 4, -299, 4, 4};
    vector<int> unsorted2 = {2, 81, -3, 54, 81, 23};
    vector<int> unsorted3 = {4, 1, 2, 3};
    vector<int> sorted = {1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 6};
    vector<int> pairs = {-2, -299, 4, -299, 50, -299, 27, 85, -299, 8, 4, -299, 4, 4};
    vector<pair<int, int>> twoD = {make_pair(2, 4), make_pair(8, 5), make_pair(1, 44), make_pair(18, 39), make_pair(19, 40), make_pair(22, 12)};
    vector<string> strings = {"g", "aYN", "t7zxg", "8n", "5V", "cgzwMm", "OoW8", "W", "iBSv", "3O7Q8", "aX"};

    cout << "Unsorted Mode: " << unsorted_mode(unsorted) << endl;
    cout << "Sorted Mode: " << sorted_mode(sorted) << endl;
    pair<int, int> p1 = unsorted_closest_integers(pairs);
    cout << "Pair: " << p1.first << ", " << p1.second << endl;
    pair<pair<int, int>, pair<int, int>> p2 = unsorted_closest_coordinates(twoD);
    cout << "Pair: (" << p2.first.first << ", " << p2.first.second << "), (" << p2.second.first << ", " << p2.second.second << ")" << endl;
    flip_sort(unsorted2);
    peak_valley_sort(unsorted3);
    length_alpha_sort(strings);

    return 0;
}