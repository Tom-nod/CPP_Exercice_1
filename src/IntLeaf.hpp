#pragma once

#include "Leaf.hpp"

class IntLeaf : public Leaf {
    public:
    IntLeaf(int number)
    :_number{number}{
        setKind(NodeKind::INT);
    }

    const std::string print() const override {
        return std::to_string(_number);
    }

    int data() const {
        return _number;
    }

    static std::unique_ptr<IntLeaf> make_ptr(int number){
        return std::make_unique<IntLeaf>(number);
    }

    private:
    int             _number;
};