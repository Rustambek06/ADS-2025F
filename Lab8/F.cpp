#include <iostream>
#include <string>
#include <vector>

struct State {
    int len, link;
    std::vector<int> next;

    State(int alphabet_size = 26) : len(0), link(-1), next(alphabet_size, -1) {}
};

class SuffixAutomaton {
public:
    std::vector<State> st;
    int last;

    SuffixAutomaton(const std::string& s) {
        st.emplace_back(); // root
        last = 0;

        for (char c : s) {
            extend(c);
        }
    }

    void extend(char ch) {
        int c = ch - 'a';
        int cur = (int)st.size();
        st.emplace_back();
        st[cur].len = st[last].len + 1;

        int p = last;
        while (p != -1 && st[p].next[c] == -1) {
            st[p].next[c] = cur;
            p = st[p].link;
        }

        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = (int)st.size();
                st.emplace_back();
                st[clone].len = st[p].len + 1;
                st[clone].next = st[q].next;
                st[clone].link = st[q].link;

                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }

                st[q].link = st[cur].link = clone;
            }
        }

        last = cur;
    }

    long long countDistinctSubstrings() const {
        long long total = 0;
        for (size_t i = 1; i < st.size(); ++i) {
            total += st[i].len - st[st[i].link].len;
        }
        return total;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    SuffixAutomaton sa(s);
    std::cout << sa.countDistinctSubstrings() << "\n";
    return 0;
}
