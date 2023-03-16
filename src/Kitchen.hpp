#pragma once

#include <set>
#include <utility>

#include "../lib/Unit.hpp"
#include "../lib/Ingredient.hpp"

class Kitchen
{
    public:
    const Unit& register_unit(const Unit unit){
        auto [tmp, trash] = _units.emplace(std::move(unit));
        return *tmp;
    }

    const Ingredient& register_ingredient(const Ingredient ingredient){
        auto [tmp, trash] = _ingredients.emplace(std::move(ingredient));
        return *tmp;
    }

    const Unit* find_unit(const std::string& search) const{
        const auto find =  _units.find(search);
        if(find != _units.end()){
            return &(*find);
        }
        return nullptr;
    }

    const Ingredient* find_ingredient(const std::string& search){
        const auto find =  _ingredients.find(search);
        if(find != _units.end()){
            return &(*find);
        }
        return nullptr;
    }

    private:
    struct CompareName {
        public :
        bool operator()(const Unit& u1, const Unit& u2) const { return u1.name < u2.name; }
        bool operator()(const Unit& unit, const std::string& str) const { return unit.name < str; }
        bool operator()(const std::string& str, const Unit& unit) const { return str < unit.name; }
        
        bool operator()(const Ingredient& i1, const Ingredient& i2) const { return i1 < i2; }
        bool operator()(const Ingredient& i1, const std::string& str) const { return i1 < str; }
        bool operator()(const std::string& str, const Ingredient& i1) const { return str < i1; }
    };

    std::set<Unit, CompareName>         _units;
    std::set<Ingredient, CompareName>   _ingredients;
};
