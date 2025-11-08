#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

const long long P = 31;
const long long MOD1 = 1'000'000'007;
const long long MOD2 = 1'000'000'009;

struct Hash {
    std::vector<long long> h1, h2, p1, p2;

    Hash(const std::string& s) {
        int n = s.size();
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            h1[i + 1] = (h1[i] * P + s[i]) % MOD1;
            h2[i + 1] = (h2[i] * P + s[i]) % MOD2;
            p1[i + 1] = (p1[i] * P) % MOD1;
            p2[i + 1] = (p2[i] * P) % MOD2;
        }
    }

    std::pair<long long, long long> get(int l, int r) const {
        long long x1 = (h1[r] - h1[l] * p1[r - l] % MOD1 + MOD1) % MOD1;
        long long x2 = (h2[r] - h2[l] * p2[r - l] % MOD2 + MOD2) % MOD2;
        return {x1, x2};
    }
};

struct pair_hash {
    std::size_t operator()(const std::pair<long long, long long>& p) const {
        return std::hash<long long>()(p.first) ^ std::hash<long long>()(p.second);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    int n = s.size();

    int q;
    std::cin >> q;

    std::vector<std::pair<int, int>> queries(q);
    std::unordered_set<int> lengths;

    for (int i = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r;
        queries[i] = {l - 1, r}; // 0-based
        lengths.insert(r - (l - 1));
    }

    Hash hs(s);

    // Для каждой длины — частоты всех подстрок этой длины
    std::unordered_map<int, std::unordered_map<std::pair<long long, long long>, int, pair_hash>> freq;

    for (int len : lengths) {
        for (int i = 0; i + len <= n; ++i) {
            auto h = hs.get(i, i + len);
            freq[len][h]++;
        }
    }

    for (auto [l, r] : queries) {
        int len = r - l;
        auto h = hs.get(l, r);
        std::cout << freq[len][h] << "\n";
    }

    return 0;
}
