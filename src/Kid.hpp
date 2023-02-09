#pragma once

#include <iostream>

class Kid {
    public:
    Kid(const std::string& name, const int money)
        :_name(name), _money(money)
    {
        _name = name;
        _money = money;
    }

    std::string get_name() const {
        return _name;
    }

    int get_money() const {
        return _money;
    }

    private:
    std::string          _name;
    int                 _money;
};

std::ostream& operator<<(std::ostream& stream, const Kid& kid) {
    return stream << kid.get_name() << " has " << kid.get_money() << " euros.";
}