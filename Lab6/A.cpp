#include <iostream>
#include <string>
#include <algorithm>
bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }
    return false;
}

bool compareChars(char c1, char c2) {
    bool v1 = isVowel(c1);
    bool v2 = isVowel(c2);
    
    if (v1 && v2) {
        return std::tolower(c1) < std::tolower(c2);
    }
    if (!v1 && !v2) {
        return std::tolower(c1) < std::tolower(c2);
    }
    return v1;
}

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end(), compareChars);
    std::cout << s << std::endl;
}