#include <iostream>
#include <vector>
// ��?�Τ_�ͦ��}��^?��
void generatePowerSet(const std::vector<char>& set, int index, std::vector<char> currentSet, std::vector<std::vector<char>>& allSubsets) {
    // �p�G?�춰�X�������A??�e�l���[�J�Ҧ��l�������X��
    if (index == set.size()) {
        allSubsets.push_back(currentSet);
        return;
    }

    // ���]�A?�e��������?
    generatePowerSet(set, index + 1, currentSet, allSubsets);

    // �]�A?�e��������?
    currentSet.push_back(set[index]);
    generatePowerSet(set, index + 1, currentSet, allSubsets);
}

int main() {
    std::vector<char> set = { 'a', 'b', 'c' }; // �ܨҶ��X
    std::vector<std::vector<char>> allSubsets; // �Τ_�O�s?����?�G

    generatePowerSet(set, 0, {}, allSubsets);

    // ?�X?�G
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
