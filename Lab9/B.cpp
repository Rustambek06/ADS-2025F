#include <iostream>
#include <string>
#include <vector>

std::vector<int> buildLps(const std::string &pattern) {
    int m = static_cast<int>(pattern.size());
    std::vector<int> lps(m, 0);

    int len = 0, i = 1;

    while(i < m) {
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

int kmpSearch(const std::string &password, std::string &pattern) {
    int n = static_cast<int>(password.size());
    int m = static_cast<int>(pattern.size());

    std::vector<int> lps = buildLps(pattern);
    int i = 0, j = 0;

    int mathcCounter = 0;

    while(i < n) {
        if (password[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                mathcCounter += 1;
                j = lps[j - 1];
                continue;
                // return i - j;
            } 
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;      
            }
        }
    }

    return mathcCounter;
}

int main () {
    std::string s; int K;
    std::string T;
    std::cin >> s >> K >> T;

    if (kmpSearch(T, s) >= K) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}