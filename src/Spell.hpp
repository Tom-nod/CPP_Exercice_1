#pragma once

#include "Card.hpp"

enum class SpellType {Normal, Equip, Continuous, QuickPlay, Field};

const std::string to_string(const SpellType spell) {
    switch (spell)
    {
    case SpellType::Normal:
        return "Normal";
        break;
    case SpellType::Equip:
        return "Equip";
        break;
    case SpellType::Continuous:
        return "Continuous";
        break;
    case SpellType::QuickPlay:
        return "Quick-Play";
        break;
    case SpellType::Field:
        return "Field";
    }
    return "";
}

class Spell : public Card {
    public:
        Spell(const std::string& id, const std::string& name, SpellType spell)
        : Card(id, CardType::Spell), _spell(spell)
        {
            set_name(name);
            _symbol = u8"魔";
        }

        SpellType get_spell_type() const {
            return _spell;
        }

    private:
        SpellType           _spell;
};