#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> list1(n);
    for (int i = 0; i < n; i++) {
        std::cin >> list1[i];
    }
    
    std::vector<int> list2(m);
    for (int i = 0; i < m; i++) {
        std::cin >> list2[i];
    }
    
    // Use unordered_map to count frequencies in list1
    std::unordered_map<int, int> freq;
    for (int num : list1) {
        freq[num]++;
    }
    
    // Check list2 and print common numbers
    bool found = false;
    std::sort(list2.begin(), list2.end());
    for (int num : list2) {
        if (freq[num] > 0) {
            std::cout << num << " ";
            freq[num]--;
            found = true;
        }
    }
    
    // If no common numbers, ensure a newline is printed
    if (!found && (n > 0 || m > 0)) {
        std::cout << std::endl;
    }
    
    return 0;
}