#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        mp[x]++; 
    }

    int maxCount = -1;
    for (const auto& p : mp) {
        if (p.second > maxCount) {
            maxCount = p.second;
        }
    }

    std::vector<int> modes;
    for (const auto& p : mp) {
        if (p.second == maxCount) {
            modes.push_back(p.first);
        }
    }

    std::sort(modes.begin(), modes.end(), std::greater<int>());

    for (int x : modes) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
