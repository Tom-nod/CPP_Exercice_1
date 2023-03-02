/* This files is for you.  You can compile and run it freely. */

#include <iostream>

#include "IntLeaf.hpp"
#include "StringLeaf.hpp"
#include "ArrayNode.hpp"
#include "ObjectNode.hpp"

int main()
{
    auto truenode_ptr = IntLeaf::make_ptr(1);
    std::cout << "truenode : " << truenode_ptr->node_count() << std::endl;

    auto falsenode_ptr = IntLeaf::make_ptr(0);
    auto arraynode_ptr = ArrayNode::make_ptr();
    arraynode_ptr->push_back(std::move(truenode_ptr));
    arraynode_ptr->push_back(std::move(falsenode_ptr));
    std::cout << "arraynode : " << arraynode_ptr->node_count() << std::endl;

    auto stringnode_ptr = StringLeaf::make_ptr("Hello world");
    std::cout << "stringnode : " << stringnode_ptr->node_count() << std::endl;

    auto intnode_ptr = IntLeaf::make_ptr(1);
    std::cout << "intnode : " << intnode_ptr->node_count() << std::endl;

    auto objectnode_ptr = ObjectNode::make_ptr();
    objectnode_ptr->insert("array", std::move(arraynode_ptr));
    objectnode_ptr->insert("string", std::move(stringnode_ptr));
    objectnode_ptr->insert("int", std::move(intnode_ptr));
    std::cout << "objectnode : " << objectnode_ptr->node_count() << std::endl;

    return 0;
}