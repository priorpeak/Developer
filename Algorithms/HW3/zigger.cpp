#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {3, 1, 4, 5, 3, 7, 2};

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";

    cout << endl;

    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (i % 2 == 0)
        {
            if (vec.at(i) > vec.at(i + 1))
                swap(vec.at(i), vec.at(i + 1));
        }
        else
        {
            if (vec.at(i) <= vec.at(i + 1))
                swap(vec.at(i), vec.at(i + 1));
        }
    }

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";

    return 0;
}