#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define ll long long
using namespace std;

const int mod = 1e9 + 7;

void precount(vector<ll>& pow, int size) {
    pow.resize(size + 1);
    pow[0] = 1;
    for (int i = 1; i <= size; ++i) {
        pow[i] = (pow[i - 1] * 11) % mod;
    }
}
 
ll calc_hash(const string& s, const vector<ll>& pow) {
    ll h = 0;
    for (int i = 0; i < s.size(); ++i) {
        h = (h + ((char(s[i]) + 0) - 47) * pow[i] + mod) % mod;
    }
    return h;
}

int main() {
    int n; cin >> n;
    string s1;
    vector<string> v2;
    unordered_set<string> st;
    for (int i = 0; i < 2 * n; i++) {
        cin >> s1;
        v2.push_back(s1);
        st.insert(s1);
    }
    vector <ll> pow;
    precount(pow, 100);
    int count = 0;
    for (string s : v2) {
        if (count == n) break;
        ll h = calc_hash(s, pow);
        string hs = to_string(h);
        if (st.count(hs)) {
            cout << "Hash of string \"" << s << "\" is " << hs << endl;
            count++;
        }
    }

    return 0;
}