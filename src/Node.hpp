#pragma once

#include <string>

#include "InstanceCounter.hpp"

class Node : public InstanceCounter {
    public:
    virtual const std::string print() const {
        return nullptr;
    }
    
    protected:
    Node(){

    }
    
    private:
};