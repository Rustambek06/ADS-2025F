#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }

    if (st.empty()) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
