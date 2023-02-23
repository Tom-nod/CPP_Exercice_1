/* This files is for you.  You can compile and run it freely. */

#include <iostream>

#include "IntLeaf.hpp"
#include "StringLeaf.hpp"

int main()
{
    IntLeaf leaf = IntLeaf{1};
    std::cout << leaf.data() << std::endl;
    std::cout << leaf.print() << std::endl;

    StringLeaf strleaf = StringLeaf{"Hello World"};
    std::cout << strleaf.data() << std::endl;
    std::cout << strleaf.print() << std::endl;

    return 0;
}