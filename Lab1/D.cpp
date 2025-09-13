#include <iostream>
#include <string>

bool is_balanced(const std::string& s, int l, int r) {
    if (l > r) return true;  // пустая строка

    if (s[l] == s[r]) {
        return is_balanced(s, l + 1, r - 1);
    }

    for (int mid = l; mid < r; ++mid) {
        if (is_balanced(s, l, mid) && is_balanced(s, mid + 1, r)) {
            return true;
        }
    }

    return false;
}

int main() {
    std::string s;
    std::cin >> s;

    if (is_balanced(s, 0, static_cast<int>(s.size()) - 1)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
