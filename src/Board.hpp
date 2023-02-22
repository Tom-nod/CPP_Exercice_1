#pragma once

#include <vector>
#include <memory>
#include <utility>

#include "Monster.hpp"
#include "Spell.hpp"
#include "Trap.hpp"

class Board {
    public:
        bool put(std::unique_ptr<Card> card){
            if(_monster.size() == 5){
                return false;
            }
            _monster.emplace_back(std::move(card));
            return true;
        }

    private:
        std::vector<std::unique_ptr<Card>>            _monster;
};