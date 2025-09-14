#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> names(n);
    for (int i = 0; i < n; i++) {
        std::cin >> names[i];
    }

    std::vector<std::string> uniqueSeq;
    uniqueSeq.push_back(names[0]);
    for (int i = 1; i < n; i++) {
        if (names[i] != names[i - 1]) {
            uniqueSeq.push_back(names[i]);
        }
    }

    std::cout << "All in all: " << uniqueSeq.size() << "\n";
    std::cout << "Students:\n";

    for (int i = (int)uniqueSeq.size() - 1; i >= 0; i--) {
        std::cout << uniqueSeq[i] << "\n";
    }

    return 0;
}
