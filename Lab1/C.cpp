#include <iostream>
#include <string>
#include <deque>

int main() {
    std::string str_1, str_2, res_1 = "", res_2 = "";
    std::cin >> str_1 >> str_2;

    std::deque<char> deq_1, deq_2;
    
    for (char c : str_1) {
        if (c == '#'){
            if (!deq_1.empty()) deq_1.pop_back();
            continue;
        }
        deq_1.push_back(c);
    }

    for (char c : str_2) {
        if (c == '#'){
            if (!deq_2.empty()) deq_2.pop_back();
            continue;
        }
        deq_2.push_back(c);
    }

    for (char c : deq_1) res_1 += c;
    for (char c : deq_2) res_2 += c;

    if (res_1 == res_2) std::cout << "Yes";
    else std::cout << "No";
}
