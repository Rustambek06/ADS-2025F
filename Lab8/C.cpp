#include <iostream>
#include <string>
#include <vector>

const long long P = 31;
const long long MOD1 = 1000000007LL;
const long long MOD2 = 1000000009LL;

struct Hash {
    std::vector<long long> h1, h2, p1, p2;
    Hash(const std::string &s) {
        int n = (int)s.size();
        h1.assign(n+1, 0);
        h2.assign(n+1, 0);
        p1.assign(n+1, 1);
        p2.assign(n+1, 1);
        for (int i = 0; i < n; i++) {
            h1[i+1] = (h1[i] * P + (unsigned char)s[i]) % MOD1;
            h2[i+1] = (h2[i] * P + (unsigned char)s[i]) % MOD2;
            p1[i+1] = (p1[i] * P) % MOD1;
            p2[i+1] = (p2[i] * P) % MOD2;
        }
    }
    std::pair<long long,long long> get(int l, int r) const {
        long long x1 = (h1[r] - (h1[l] * p1[r-l]) % MOD1 + MOD1) % MOD1;
        long long x2 = (h2[r] - (h2[l] * p2[r-l]) % MOD2 + MOD2) % MOD2;
        return {x1, x2};
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string big;
    int k;
    std::cin >> big >> k;
    std::vector<std::string> small(k);
    for (int i = 0; i < k; i++) std::cin >> small[i];

    int n = (int)big.size();
    Hash hBig(big);

    // Precompute hashes of small tapes
    std::vector<std::pair<long long,long long>> hSmall(k);
    std::vector<int> len(k);
    for (int j = 0; j < k; j++) {
        len[j] = (int)small[j].size();
        Hash hs(small[j]);
        hSmall[j] = hs.get(0, len[j]);
    }

    // Difference array for coverage on positions [0..n-1]
    std::vector<int> diff(n+1, 0);

    // For each start i and each small tape, mark interval if it matches
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int L = len[j];
            if (i + L <= n) {
                auto hSub = hBig.get(i, i + L);
                if (hSub == hSmall[j]) {
                    // Mark coverage of positions [i, i+L-1]
                    diff[i] += 1;
                    diff[i + L] -= 1;
                }
            }
        }
    }

    // Build coverage counts via prefix sum and check
    int cur = 0;
    for (int pos = 0; pos < n; pos++) {
        cur += diff[pos];
        if (cur == 0) {
            std::cout << "NO\n";
            return 0;
        }
    }
    std::cout << "YES\n";
    return 0;
}
