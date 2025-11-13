#include <iostream>
#include <string>
#include <vector>

std::vector<int> buildLps(const std::string &pattern) {
    int m = static_cast<int>(pattern.size());
    std::vector<int> lps(m, 0);
    int len = 0;
    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
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
    std::vector<int> lps = buildLps(pattern);
    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                return i - j; // match found at index (i - j)
            }  
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1; // no match found
}

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    int n = static_cast<int>(s1.size());
    std::string doubled = s1 + s1;

    int pos = kmpSearch(doubled, s2);

    if (pos == -1 || pos >= n) {
        std::cout << -1;
    } else {
        std::cout << (n - pos) % n;
    }
    return 0;
}