#pragma once

#include <string>
#include <memory>
#include <utility>
#include <algorithm>

#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

#define NodePtr std::unique_ptr<Node>

class Node : public InstanceCounter {
    public:
    virtual const std::string print() const {
        return nullptr;
    }

    virtual ~Node(){};

    void setKind(NodeKind kind){
        _kind = kind;
    }

    NodeKind kind(){
        return _kind;
    }

    virtual int height() const {
        return 0u;
    }

    virtual int node_count() const {
        return 0u;
    }
    
    protected:
    Node(){

    }
    
    private:
    NodeKind                _kind;
};