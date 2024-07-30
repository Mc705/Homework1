#include <iostream>
#include <vector>
// 函?用于生成并返回?集
void generatePowerSet(const std::vector<char>& set, int index, std::vector<char> currentSet, std::vector<std::vector<char>>& allSubsets) {
    // 如果?到集合的末尾，??前子集加入所有子集的集合中
    if (index == set.size()) {
        allSubsets.push_back(currentSet);
        return;
    }

    // 不包括?前元素的情?
    generatePowerSet(set, index + 1, currentSet, allSubsets);

    // 包括?前元素的情?
    currentSet.push_back(set[index]);
    generatePowerSet(set, index + 1, currentSet, allSubsets);
}

int main() {
    std::vector<char> set = { 'a', 'b', 'c' }; // 示例集合
    std::vector<std::vector<char>> allSubsets; // 用于保存?集的?果

    generatePowerSet(set, 0, {}, allSubsets);

    // ?出?果
    std::cout << "Power set:\n";
    for (const auto& subset : allSubsets) {
        std::cout << "{ ";
        for (const auto& elem : subset) {
            std::cout << elem << " ";
        }
        std::cout << "}\n";
    }

    return 0;
}
