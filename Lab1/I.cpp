#include <iostream>
#include <cmath>
#include <deque>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::deque<char> dq;
    for (int i = 0; i < n; i++) {
        char c;
        std::cin >> c;
        dq.push_back(c);
    }

    while (dq.size() > 1) {
        char front = dq.front();
        if (front == 'K') {
            auto it = std::find(dq.begin() + 1, dq.end(), 'S');
            if (it != dq.end()) {
                dq.erase(it);
            } else {
                dq.pop_front();
            }
        } else if (front == 'S') {
            auto it = std::find(dq.begin() + 1, dq.end(), 'K');
            if (it != dq.end()) {
                dq.erase(it);
            } else {
                dq.pop_front();
            }
        } 

    }

    if (dq.front() == 'K') {
        std::cout << "KATSURAGI";
    } else {
        std::cout << "SAKAYANAGI";
    }
}