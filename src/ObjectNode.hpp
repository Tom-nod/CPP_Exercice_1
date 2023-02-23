#pragma once

#include "Node.hpp"

class ObjectNode : public Node {
    public:
    ObjectNode(){

    }

    const std::string print() const override {
        return "{}";
    }

    private:

};