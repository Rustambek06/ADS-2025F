#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <array>

struct AhoCorasick {
    struct Node {
        std::array<int, 26> next{};
        int link = -1;                   // суффиксная ссылка
        std::vector<int> out;            // индексы шаблонов, которые оканчиваются здесь
        Node() { next.fill(-1); }
    };

    std::vector<Node> trie;

    AhoCorasick() { trie.emplace_back(); } // корень

    static int idx(char c) { return c - 'a'; }

    void add_pattern(const std::string& s, int id) {
        int v = 0;
        for (char ch : s) {
            int c = idx(ch);
            if (trie[v].next[c] == -1) {
                trie[v].next[c] = (int)trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[c];
        }
        trie[v].out.push_back(id);
    }

    void build() {
        std::queue<int> q;
        // инициализируем переходы корня
        for (int c = 0; c < 26; ++c) {
            int u = trie[0].next[c];
            if (u != -1) {
                trie[u].link = 0;
                q.push(u);
            } else {
                trie[0].next[c] = 0; // оптимизация: делаем явный переход в корень
            }
        }
        // BFS по слоям, строим ссылки
        while (!q.empty()) {
            int v = q.front(); q.pop();
            int link_v = trie[v].link;
            for (int c = 0; c < 26; ++c) {
                int u = trie[v].next[c];
                if (u != -1) {
                    trie[u].link = trie[link_v].next[c];
                    // добавляем выходы из суффиксной ссылки
                    for (int pid : trie[trie[u].link].out) {
                        trie[u].out.push_back(pid);
                    }
                    q.push(u);
                } else {
                    trie[v].next[c] = trie[link_v].next[c];
                }
            }
        }
    }

    // Возвращает частоты шаблонов по их индексам
    std::vector<long long> match_all(const std::string& text, int patterns_count) const {
        std::vector<long long> freq(patterns_count, 0LL);
        int v = 0;
        for (char ch : text) {
            int c = idx(ch);
            v = trie[v].next[c];
            // инкрементируем все шаблоны, заканчивающиеся в текущей вершине
            for (int pid : trie[v].out) {
                freq[pid] += 1;
            }
        }
        return freq;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true) {
        int M;
        if (!(std::cin >> M)) return 0;
        if (M == 0) break;

        std::vector<std::string> patterns(M);
        for (int i = 0; i < M; ++i) {
            std::cin >> patterns[i];
        }
        std::string text;
        std::cin >> text;

        // Строим автомат
        AhoCorasick ac;
        for (int i = 0; i < M; ++i) {
            ac.add_pattern(patterns[i], i);
        }
        ac.build();

        // Ищем все вхождения
        std::vector<long long> freq = ac.match_all(text, M);

        // Находим максимум
        long long mx = 0;
        for (int i = 0; i < M; ++i) {
            if (freq[i] > mx) mx = freq[i];
        }

        // Вывод: максимальная частота и доминирующие паттерны в порядке ввода
        std::cout << mx << "\n";
        for (int i = 0; i < M; ++i) {
            if (freq[i] == mx) {
                std::cout << patterns[i] << "\n";
            }
        }
    }
    return 0;
}
