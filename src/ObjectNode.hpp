#pragma once

#include <map>

#include "Node.hpp"

class ObjectNode : public Node {
    public:
    ObjectNode(){
        setKind(NodeKind::OBJECT);
    }

    const std::string print() const override {
        return "{}";
    }

    static std::unique_ptr<ObjectNode> make_ptr(){
        return std::make_unique<ObjectNode>();
    }

    private:
    std::map<std::string, NodePtr>             _map;
};