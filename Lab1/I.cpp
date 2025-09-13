#include <iostream>
#include <queue>
#include <string>

int main() {
    int n;
    if (!(std::cin >> n)) return 0;
    std::string s;
    std::cin >> s;

    std::queue<int> qS; // индексы Sakayanagi ('S')
    std::queue<int> qK; // индексы Katsuragi ('K')

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'S') qS.push(i);
        else qK.push(i);
    }

    while (!qS.empty() && !qK.empty()) {
        int iS = qS.front();
        int iK = qK.front();
        qS.pop();
        qK.pop();
        if (iS < iK) {
            // S действует раньше, выбивает K, S возвращается в очередь
            qS.push(iS + n);
        } else {
            // K действует раньше, выбивает S, K возвращается в очередь
            qK.push(iK + n);
        }
    }

    if (qS.empty()) {
        std::cout << "KATSURAGI\n";
    } else {
        std::cout << "SAKAYANAGI\n";
    }

    return 0;
}
