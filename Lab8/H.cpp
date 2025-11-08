#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

const long long P = 911;
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

    int K;
    std::cin >> K;
    std::vector<std::string> s(K);
    for (int i = 0; i < K; ++i) std::cin >> s[i];

    std::vector<Hash> hashes;
    for (int i = 0; i < K; ++i) hashes.emplace_back(s[i]);

    int low = 1, high = s[0].size();
    std::string answer;

    while (low <= high) {
        int len = (low + high) / 2;
        std::unordered_map<std::pair<long long, long long>, std::vector<int>, pair_hash> count;

        // Сохраняем хеши всех подстрок длины len из первой строки
        for (int i = 0; i + len <= s[0].size(); ++i) {
            auto h = hashes[0].get(i, i + len);
            count[h] = {i}; // сохраняем позицию
        }

        // Пересечение: оставляем только те хеши, которые есть во всех строках
        for (int k = 1; k < K; ++k) {
            std::unordered_set<std::pair<long long, long long>, pair_hash> current;
            for (int i = 0; i + len <= s[k].size(); ++i) {
                current.insert(hashes[k].get(i, i + len));
            }

            for (auto it = count.begin(); it != count.end();) {
                if (current.find(it->first) == current.end()) {
                    it = count.erase(it);
                } else {
                    ++it;
                }
            }
        }

        if (!count.empty()) {
            // нашли общую подстроку длины len
            int pos = count.begin()->second[0];
            answer = s[0].substr(pos, len);
            low = len + 1;
        } else {
            high = len - 1;
        }
    }

    std::cout << answer << "\n";
    return 0;
}
