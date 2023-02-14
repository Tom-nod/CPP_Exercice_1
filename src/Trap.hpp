#pragma once

#include "Card.hpp"

enum class TrapType {Normal, Continuous, Counter};

const std::string to_string(const TrapType spell) {
    switch (spell)
    {
    case TrapType::Normal:
        return "Normal";
        break;
    case TrapType::Continuous:
        return "Continuous";
        break;
    case TrapType::Counter:
        return "Counter";
    }
    return "";
}

class Trap : public Card {
    public:
        Trap(const std::string& id, const std::string& name, TrapType trap)
        : Card(id, CardType::Trap), _trap(trap)
        {
            set_name(name);
        }

        TrapType get_trap_type() const {
            return _trap;
        }

    private:
        TrapType           _trap;
};