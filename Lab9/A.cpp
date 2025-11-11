#include <iostream>
#include <string>
#include <vector>
#include <cmath>

std::vector<int> buildLPS(const std::string &pattern) {
    int m = static_cast<int>(pattern.size());
    std::vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int kmpSearch(const std::string &text, const std::string &pattern) {
    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());
    std::vector<int> lps = buildLPS(pattern);
    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m)
                return i - j; // found pattern starting at index (i - j)
        } else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string A, B;
    std::cin >> A >> B;

    int lenA = static_cast<int>(A.size());
    int lenB = static_cast<int>(B.size());
    int limit = (lenB + lenA - 1) / lenA + 2; // ceil(lenB / lenA) + 2

    std::string repeated;
    repeated.reserve(lenA * limit);
    for (int i = 0; i < limit; i++) 
        repeated += A;

    int pos = kmpSearch(repeated, B);
    if (pos == -1) {
        std::cout << -1;
        return 0;
    }

    int end_index = pos + lenB;          
    int repeats_needed = (end_index + lenA - 1) / lenA; // ceiling division

    std::cout << repeats_needed;
    return 0;
}
