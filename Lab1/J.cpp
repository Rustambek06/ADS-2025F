#include <iostream>
#include <deque>
#include <string>

int main() {
    std::deque<int> dq;
    char op;

    while (std::cin >> op) {
        if (op == '!') {
            break; // конец работы
        } 
        else if (op == '+') {
            int x;
            std::cin >> x;
            dq.push_front(x);
        } 
        else if (op == '-') {
            int x;
            std::cin >> x;
            dq.push_back(x);
        } 
        else if (op == '*') {
            if (dq.empty()) {
                std::cout << "error\n";
            } else if (dq.size() == 1) {
                int val = dq.front();
                std::cout << val + val << "\n";
                dq.pop_front();
            } else {
                int first = dq.front();
                int last = dq.back();
                std::cout << first + last << "\n";
                dq.pop_front();
                dq.pop_back();
            }
        }
    }

    return 0;
}
