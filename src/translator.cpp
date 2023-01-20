#include <iostream>
#include <vector>
#include <bits/stdc++.h>

std::vector<std::string> make_exit_commands(){
    return {"q", "e", "quit", "exit"};
}

int main() {
    std::string command;
    auto lst = make_exit_commands();
    std::map<std::string, std::string> map;
    std::vector<std::string> history;
    while (true) {
        std::cout << "This is a translator, it becames something..." << std::endl;
        std::cin >> command;
        if(std::count(lst.begin(), lst.end(), command)){
            break;
        }
        if(command == "add"){
            std::string w1, w2;
            std::cin >> w1 >> w2;
            map[w1] = w2;
            std::cout << w1 << " => " << w2 << std::endl;
            history.emplace_back("add " + w1 + " " + w2);
        } else if(command == "translate"){
            std::string line;
            std::stringstream words;
            std::string separator = "";
            std::getline(std::cin, line);
            words << line;
            while(!words.eof()){
                std::string word;
                words >> word;
                if (auto search = map.find(word); search != map.end()){
                    std::cout << separator << search->second;
                } else{
                    std::cout << separator << "???";
                }
                separator = " ";
            }
            std::cout << std::endl;
        } else if(command == "print"){
            for (const auto& [key, value] : map){
                std::cout << key << " => " << value << std::endl;
            }
        } else if(command == "save"){
            std::string name;
            std::cin >> name;
        }
    }

    return 0;
}