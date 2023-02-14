#pragma once

#include <string>

enum class CardType {Monster, Spell, Trap};

const std::string to_string(const CardType ct) {
    switch (ct)
    {
    case CardType::Monster:
        return "Monster";
        break;
    case CardType::Spell:
        return "Spell";
        break;
    case CardType::Trap:
        return "Trap";
        break;
    }
    return "";
}

class Card {
    public:
        Card(const std::string& id, CardType type)
        :_id(id), _type(type){
            _name = "";
            _description = "";
        }

        const std::string get_id() const {
            return _id;
        }

        CardType get_type() const {
            return _type;
        }

        const std::string get_name() const {
            return _name;
        }

        const std::string get_description() const {
            return _description;
        }

        void set_name(const std::string& name) {
            _name = name;
        }

        void set_description(const std::string& description) {
            _description = description;
        }

    private:
        std::string             _id;
        CardType                _type;
        std::string             _name;
        std::string             _description;
};