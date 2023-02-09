#pragma once

#include <iostream>
#include <cmath>
#include <optional>

#include <Plush.hpp>

class PlushStore {
    public:
    PlushStore(const std::string& name)
        :_name(name){
            _name = name;
            _wealth_amount = 0;
            _stock_size = 0;
            _debt_amount = 0;
            _experience = 0;
        }
    
    std::string get_name() const{
        return _name;
    }

    int get_wealth_amount() const{
        return _wealth_amount;
    }

    int get_stock_size() const {
        return _stock_size;
    }

    int get_debt_amount() const {
        return _debt_amount;
    }

    void loan(int amount) {
        _wealth_amount += amount;
        _debt_amount += amount * 1.1;
    }

    int make_plush(int cost) {
        int value;
        if(_wealth_amount != 0){
            ++_stock_size;
            ++_experience;
            if(cost < _wealth_amount){
                value = cost;
            } else{
                value = cost - _wealth_amount;
            }
            _wealth_amount -= cost;
            if(_wealth_amount < 0){
                _wealth_amount = 0;
            }
        }
        return value + std::max(_experience, _experience * value / 100);
    }

    int get_experience() const {
        return _experience;
    }

    std::optional<Plush> buy(int cost){
        auto plush = Plush();
        if (cost < plush.get_cost()){
            return {};
        }
        plush.set_cost(_experience);
        --_stock_size;
        _wealth_amount += cost;
        return {plush};
    }

    private:
    std::string     _name;
    int             _wealth_amount;
    int             _stock_size;
    int             _debt_amount;
    int             _experience;
};