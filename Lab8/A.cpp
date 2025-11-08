#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

const long long MOD = 1e9 + 7;

std::string hashFunction(const std::string& S) {
    long long res = 0;
    long long p = 1;
    for (char c : S) {
        long long val = (int)c;
        res = (res + (val - 47) * p) % MOD;
        p = (p * 11) % MOD;
        res %= MOD;
    }
    return std::to_string(res);
}

bool isDigitsOnly(const std::string& s) {
    for (char c : s)
        if (!isdigit(c)) return false;
    return true;
}

int main() {
    int n;
    std::cin >> n;
    n *= 2;

    std::vector<std::string> vec(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }

    std::unordered_map<std::string, bool> hashExists;
    for (auto &s : vec)
        hashExists[s] = true;

    for (auto &s : vec) {
        std::string h = hashFunction(s);
        if (hashExists.count(h)) {
            std::cout << "Hash of string \"" << s << "\" is " << h << "\n";
            hashExists.erase(h);
        }
    }

    return 0;
}