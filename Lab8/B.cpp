#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long P = 31;
const long long MOD1 = 1000000007;
const long long MOD2 = 1000000009;

struct Hash {
    vector<long long> h1, h2, p1, p2;
    Hash(const string &s) {
        int n = s.size();
        h1.resize(n+1); h2.resize(n+1);
        p1.resize(n+1); p2.resize(n+1);
        h1[0] = h2[0] = 0;
        p1[0] = p2[0] = 1;
        for (int i = 0; i < n; i++) {
            h1[i+1] = (h1[i]*P + s[i]) % MOD1;
            h2[i+1] = (h2[i]*P + s[i]) % MOD2;
            p1[i+1] = (p1[i]*P) % MOD1;
            p2[i+1] = (p2[i]*P) % MOD2;
        }
    }
    pair<long long,long long> get(int l, int r) {
        long long x1 = (h1[r] - h1[l]*p1[r-l] % MOD1 + MOD1) % MOD1;
        long long x2 = (h2[r] - h2[l]*p2[r-l] % MOD2 + MOD2) % MOD2;
        return {x1,x2};
    }
};

int main() {
    string s1, s2, base;
    cin >> s1 >> s2 >> base;
    int n = base.size();

    Hash h1(s1), h2(s2), hb(base);
    auto baseHash = hb.get(0,n);

    int cnt = 0;
    for (int i = 0; i + n <= min(s1.size(), s2.size()); i++) {
        if (h1.get(i,i+n) == baseHash && h2.get(i,i+n) == baseHash) {
            cnt++;
        }
    }
    cout << cnt;
}
