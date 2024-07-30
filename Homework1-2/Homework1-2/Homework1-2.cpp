#include <iostream>
#include <vector>
#include <string>

void generatePowerSet(const std::vector<char>& set, int index, std::vector<char> currentSet, std::vector<std::vector<char>>& allSubsets) {
    
    if (index == set.size()) {
        allSubsets.push_back(currentSet);
        return;
    }

    generatePowerSet(set, index + 1, currentSet, allSubsets);

    currentSet.push_back(set[index]);
    generatePowerSet(set, index + 1, currentSet, allSubsets);
}

int main() {
    std::vector<char> set; 
    std::vector<std::vector<char>> allSubsets; 

    std::string input;
    std::cout << "請輸入集合元素（例如：abc）：";
    std::getline(std::cin, input);

    
    for (char c : input) {
        set.push_back(c);
    }

    
    generatePowerSet(set, 0, {}, allSubsets);

    
    std::cout << "冪集:\n";
    for (const auto& subset : allSubsets) {
        std::cout << "{ ";
        for (const auto& elem : subset) {
            std::cout << elem << " ";
        }
        std::cout << "}\n";
    }

    return 0;
}
