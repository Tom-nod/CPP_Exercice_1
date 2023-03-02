#pragma once

#include <map>
#include <iostream>

#include "Node.hpp"

class ObjectNode : public Node {
    public:
    ObjectNode(){
        setKind(NodeKind::OBJECT);
    }

    const std::string print() const override {
        std::string str = "{";
        std::string separator = "";
        for(auto const& it : _map){
            std::string key = it.first;
            auto value = it.second->print();

            str += separator + "\"" + key + "\"" + ":" + value;
            separator = ",";
        }
        str += "}";
        return str;
    }

    static std::unique_ptr<ObjectNode> make_ptr(){
        return std::make_unique<ObjectNode>();
    }

    void insert(const std::string& key, NodePtr value){
        _map.insert({key, std::move(value)});
    }

    unsigned int child_count() const {
        return _map.size();
    }

    int height() const override {
        if(_map.size() == 0){
            return 0u;
        }
        int height_max = 0;
        for(auto const& it : _map){
            auto value = it.second->height();
            height_max = std::max(height_max, value);
        }
        return height_max + 1;
    }

    int node_count() const override {
        int count = 0;
        for(auto const& it : _map){
            auto value = it.second->node_count();
            count += value;
        }
        return count + 1;
    }

    bool has_child(const std::string key){
        for(auto const& it : _map){
            auto key_map = it.first;
            if(key == key_map){
                return true;
            }
        }
        return false;
    }

    NodePtr at(const std::string key){
        for(auto const& it : _map){
            auto key_map = it.first;
            if(key == key_map){
                return it.second;
            }
        }
        return nullptr;
    }

    private:
    std::map<std::string, NodePtr>             _map;
};