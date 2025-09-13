#include <iostream>
#include <cmath>

int main() {
    int n, k;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::cin >> k;
    
    int min_offset = -100000000, index;
    for (int i = 0; i < n; i++) {
        if (std::abs(a[i] - k) < std::abs(min_offset)) {
            min_offset = a[i] - k;
            index = i;
        }
    }

    std::cout << index << std::endl;
    return 0;
}