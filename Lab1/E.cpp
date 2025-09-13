#include <iostream>
#include <deque>

int main() {
    const int MAX_MOVES = 1000000; // 10^6
    std::deque<int> boris;
    std::deque<int> nursik;

    for (int i = 0; i < 5; i++) {
        int card;
        std::cin >> card;
        boris.push_back(card);
    }

    for (int i = 0; i < 5; i++) {
        int card;
        std::cin >> card;
        nursik.push_back(card);
    }

    int moves = 0;
    while (moves < MAX_MOVES) {

        if (boris.empty()) {
            std::cout << "Nursik " << moves;
            return 0;
        }
        if (nursik.empty()) {
            std::cout << "Boris " << moves;
            return 0;
        }

        int boris_card = boris.front();
        int nursik_card = nursik.front();
        boris.pop_front();
        nursik.pop_front();

        bool nursik_wins = (nursik_card > boris_card && !(boris_card == 0 && nursik_card == 9)) 
                           || (nursik_card == 0 && boris_card == 9);

        if (nursik_wins) {
            nursik.push_back(boris_card);
            nursik.push_back(nursik_card);
        } else {
            boris.push_back(boris_card);
            boris.push_back(nursik_card);
        }

        moves++;
    }

    std::cout << "blin nichya";
    return 0;
}
