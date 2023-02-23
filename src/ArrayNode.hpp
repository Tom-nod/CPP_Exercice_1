#pragma once

#include <vector>

#include "Node.hpp"

class ArrayNode : public Node {
    public:
    ArrayNode(){
        setKind(NodeKind::ARRAY);
    }

    const std::string print() const override {
        return "[]";
    }

    static std::unique_ptr<ArrayNode> make_ptr(){
        return std::make_unique<ArrayNode>();
    }

    private:
    std::vector<NodePtr>        _array;
};