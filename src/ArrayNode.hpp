#pragma once

#include <vector>

#include "Node.hpp"

class ArrayNode : public Node {
    public:
    ArrayNode(){

    }

    const std::string print() const override {
        return "[]";
    }

    private:
    std::vector<Node>        _array;
};