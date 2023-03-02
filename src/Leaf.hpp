#pragma once

#include "Node.hpp"

class Leaf : public Node {
    public:
    int height() const {
        return 0u;
    }

    int node_count() const {
        return 1u;
    }

    protected:
    Leaf(){

    }
    
    private:
};