#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    if (!(std::cin >> N)) return 0;
    std::vector<long long> p(N + 1, 0); // p[0] = 0 as hash of empty prefix
    for (int i = 1; i <= N; ++i) std::cin >> p[i];

    std::string s;
    s.reserve(N);

    unsigned long long pow2 = 1; // 2^(i-1)
    for (int i = 1; i <= N; ++i) {
        __int128 diff = (__int128)p[i] - (__int128)p[i - 1];
        // compute (S_i - 97) = diff / 2^(i-1)
        long long x = (long long)(diff / (__int128)pow2);
        // x should be in [0..25] for lowercase letters
        char ci = char(x + 97);
        s.push_back(ci);
        pow2 <<= 1; // multiply by 2 for next position
    }

    std::cout << s << "\n";
    return 0;
}
