#include <iostream>
#include <vector>
#include "jjalloc.h"

int main(int argc, char const *argv[])
{
    int ia[5] = {0, 1, 2, 3, 4};
    std::vector<int, JJ::allocator<int>> iv{1, 2, 3, 4, 5};
    for (int i : iv)
    {
        std::cout << "i: " << i << "\n";
    }
    return 0;
}
