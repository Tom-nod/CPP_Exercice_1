#pragma once

#include "Leaf.hpp"

class StringLeaf : public Leaf {
    public:
    StringLeaf(const std::string& str)
    :_str{str}{

    }

    const std::string print() const override {
        return "\"" + _str + "\"";
    }

    const std::string data() const {
        return _str;
    }

    private:
    std::string             _str;
};