#pragma once

#include "PC.h"
#include "Pokeball.h"

// A person that captures Pokemons and makes them fight.
class Trainer{
    public:
        Trainer(const std::string& name, PC& pc)
        :_name(name), _pc(pc){

        }

        const std::array<Pokeball, 6>& pokeballs() const{
            return _pokeballs;
        }

        const std::string& name() const{
            return _name;
        }

        void capture(PokemonPtr pokemon){
            pokemon->set_trainer(*this);
            if(_iter > 5){
                _pc.transfer(std::move(pokemon));
            }
            if(pokemon != nullptr){
                _pokeballs[_iter].store(std::move(pokemon));
                ++_iter;
            }
        }

    private:
        std::string                 _name;
        PC&                         _pc;
        std::array<Pokeball, 6>     _pokeballs;
        int                         _iter = 0;
};
