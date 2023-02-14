#pragma once

#include "Card.hpp"

enum class Attribute {Dark, Divine, Earth, Fire, Light, Water, Wind};

const std::string to_symbol(const Attribute attribute) {
    switch (attribute)
    {
    case Attribute::Dark:
        return u8"闇";
        break;
    case Attribute::Divine:
        return u8"神";
        break;
    case Attribute::Earth:
        return u8"地";
        break;
    case Attribute::Fire:
        return u8"炎";
        break;
    case Attribute::Light:
        return u8"光";
        break;
    case Attribute::Water:
        return u8"水";
        break;
    case Attribute::Wind:
        return u8"風";
    }
    return "";
}

class Monster : public Card {
    public  :
        Monster(const std::string& id, const std::string& name, Attribute attribute, const std::string& type, int atk, int def)
                :Card(id, CardType::Monster), _attribute(attribute),
                 _type(type), _atk(atk), _def(def)
        { 
            set_name(name);
        }

        Attribute get_attribute() const {
            return _attribute;
        }

        int get_atk() const {
            return _atk;
        }

        int get_def() const {
            return _def;
        }

        const std::string get_description() const {
            return "[" + _type + "]\n" + Card::get_description() + "\nATK/" + std::to_string(_atk) + " DEF/" + std::to_string(_def);
        }

    private :
        Attribute               _attribute;
        std::string             _type;
        int                     _atk;
        int                     _def;
};