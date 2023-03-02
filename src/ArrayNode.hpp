#pragma once

#include <vector>
#include <iostream>

#include "Node.hpp"

class ArrayNode : public Node {
    public:
    ArrayNode(){
        setKind(NodeKind::ARRAY);
    }

    const std::string print() const override {
        std::string str = "[";
        std::string separator = "";
        for(auto i = 0; i < child_count(); ++i){
            str += separator + _array[i]->print();
            separator = ",";
        }
        str += "]";
        return str;
    }

    static std::unique_ptr<ArrayNode> make_ptr(){
        return std::make_unique<ArrayNode>();
    }

    void push_back(NodePtr node){
        _array.push_back(std::move(node));
    }

    int child_count() const {
        return _array.size();
    }

    int height() const override {
        if(_array.empty()){
            return 0;
        }
        int height_max = 0;
        for(auto i = 0; i < child_count(); ++i){
            if(_array[i]->kind() == NodeKind::ARRAY){
                height_max = std::max(height_max, _array[i]->height());
            }
        }
        return height_max + 1;
    }

    int node_count() const override {
        int count = 0;
        for(auto i = 0; i < child_count(); ++i){
            count += _array[i]->node_count();
        }
        return count + 1;
    }

    private:
    std::vector<NodePtr>        _array;
};