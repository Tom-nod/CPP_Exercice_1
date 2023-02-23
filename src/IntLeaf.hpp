#pragma once

#include "Leaf.hpp"

class IntLeaf : public Leaf{
    public:
    IntLeaf(int number)
    :_number{number}{

    }

    const std::string print() const override {
        return std::to_string(_number);
    }

    int data() const {
        return _number;
    }

    private:
    int             _number;
};