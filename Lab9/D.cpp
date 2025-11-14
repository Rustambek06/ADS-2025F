#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string toLower(const std::string &s) {
    std::string r = s;
    for (char &c : r) c = std::tolower(c);
    return r;
}

int main() {
    std::string prev;
    int N;
    std::cin >> prev >> N;

    std::vector<std::string> cities(N);
    for (int i = 0; i < N; i++) std::cin >> cities[i];

    std::string prevLow = toLower(prev);

    int best = 0;
    std::vector<std::string> ans;

    for (int i = 0; i < N; i++) {
        std::string curLow = toLower(cities[i]);
        int maxLen = std::min(prevLow.size(), curLow.size());
        int match = 0;

        for (int len = maxLen; len >= 1; len--) {
            bool ok = true;
            for (int j = 0; j < len; j++) {
                if (prevLow[prevLow.size() - len + j] != curLow[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                match = len;
                break;
            }
        }

        if (match > best) {
            best = match;
            ans.clear();
            ans.push_back(cities[i]);
        } else if (match == best && match > 0) {
            ans.push_back(cities[i]);
        }
    }

    std::cout << ans.size() << "\n";
    for (auto &s : ans) std::cout << s << "\n";

    return 0;
}
