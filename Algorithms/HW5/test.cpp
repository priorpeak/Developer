#include <iostream>
#include <vector>
#include "hw5.h"

using namespace std;

int main()
{
    // std::vector<int> small_min_heap = {-2074469549, -1991056672, -1659939278, -1827455201, 857903436, -250315153, 1680957094, 49880895, 466790725, 1948819314};
    // std::vector<int> smallest_3 = findMinK(3, small_min_heap);
    // std::cout << "smallest 3 elements are: ";
    // // should print 0, 1, 2, in any order.
    // for (auto it = smallest_3.begin(); it != smallest_3.end(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    BloomFilter bf = BloomFilter();
    bf.insert("Hello, World!");
    bf.insert("Lorem ipsum");

    std::cout << (bf.member("foo bar") ? "'foo bar' is in our bloom filter" : "'foo bar' is not in our bloom filter")
              << std::endl;

    cout << (bf.member("Hello, World!") ? "'Hello, World!' is in our bloom filter" : "'Hello, World!' is not in our bloom filter") << endl;

    return 0;
}