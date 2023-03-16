#pragma once

#include <set>
#include <utility>

#include "../lib/Unit.hpp"

class Kitchen
{
    public:
    const Unit& register_unit(const Unit unit){
        auto [tmp, trash] = _units.emplace(std::move(unit));
        return *tmp;
    }

    const Unit* find_unit(const std::string& search) const{
        const auto find =  _units.find(Unit{search});
        if(find != _units.end()){
            return &(*find);
        }
        return nullptr;
    }

    private:
    struct CompareName {
        public :
        bool operator()(const Unit& u1, const Unit& u2) const { return u1.name < u2.name; }
    };

    std::set<Unit, CompareName>         _units;
};
