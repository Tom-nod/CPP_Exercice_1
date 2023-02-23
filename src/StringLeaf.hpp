#pragma once

#include "Leaf.hpp"

class StringLeaf : public Leaf {
    public:
    StringLeaf(const std::string& str)
    :_str{str}{
        setKind(NodeKind::STRING);
    }

    const std::string print() const override {
        return "\"" + _str + "\"";
    }

    const std::string data() const {
        return _str;
    }

    static std::unique_ptr<StringLeaf> make_ptr(std::string str){
        return std::make_unique<StringLeaf>(str);
    };

    private:
    std::string             _str;
};