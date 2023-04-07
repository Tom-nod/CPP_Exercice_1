#include "ex1.hpp"

#include "../lib/concatenate.hpp"

void pairwise_concatenate(std::list<std::list<int>>& list1, std::list<std::list<int>>&& list2)
{
    auto iter = list2.begin();
    for(auto list : list1){
        concatenate(list, std::move(*iter));
        iter++;
    }
}

void pairwise_concatenate(std::list<std::list<int>>& list1, const std::list<std::list<int>>& list2){
    auto iter = list2.begin();
    for(auto list : list1){
        concatenate(list, *iter);
        iter++;
    }
}