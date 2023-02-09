#pragma once

#include <string>

// A creature that is cute and can fight other ones.
class Pokemon{
    public:
        Pokemon(const Pokemon& pokemon)
        :_name(pokemon._name), _id(pokemon.next_id++){
            
        }

        Pokemon(std::string name)
        :_name(name), _id(next_id++){
        }

        const std::string name() const {
            return _name;
        }

        int id() const {
            return _id;
        }
        
        Pokemon& operator=(const Pokemon& pokemon){
            if(this == &pokemon){
                _name = pokemon._name;
            }
            return *this;
        }

       static int next_id;

    private:
        std::string         _name;
        int                 _id;
};
