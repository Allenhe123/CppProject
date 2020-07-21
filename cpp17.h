#pragma once

#include <map>
#include <string>
#include <iostream>

void func1() {
    std::map<std::string, int> mapInst{{"he", 123}, {"zhang", 456}};
    std::map<std::string, int> mapClone{mapInst};

    if (auto [iter, wasAdded] = mapClone.insert_or_assign("zhang", 789); !wasAdded )
        std::cout << iter->first << " was reassigned" << std::endl;

    for (const auto& [key, value] : mapClone )
        std::cout << key << ", " << value << std::endl;

}