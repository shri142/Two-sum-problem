#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

std::vector<std::pair<int, int>> findPairsWithSum(const std::vector<int>& array, int targetSum) {
    std::vector<std::pair<int, int>> pairs;
    std::unordered_map<int, std::vector<int>> hashMap;

    for (int i = 0; i < array.size(); i++) {
        int complement = targetSum - array[i];
        
        if (hashMap.find(complement) != hashMap.end()) {
            for (int index : hashMap[complement]) {
                pairs.push_back(std::make_pair(index, i));
            }
        }

        hashMap[array[i]].push_back(i);
    }

    return pairs;
}

int main() {
    std::vector<int> array;
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    std::cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        int element;
        std::cin >> element;
        array.push_back(element);
    }

    int targetSum;
    std::cout << "Enter the target sum: ";
    std::cin >> targetSum;

    std::vector<std::pair<int, int>> pairs = findPairsWithSum(array, targetSum);

    std::cout << "Pairs with sum " << targetSum << " are:\n";
    for (const auto& pair : pairs) {
        std::cout << "(" << pair.first << ", " << pair.second << ")\n";
    }

    return 0;
}