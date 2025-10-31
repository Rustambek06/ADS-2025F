#include <iostream>
#include <vector>

void insert(std::vector<int> &a, int x) {
    a.push_back(x);
    size = a.size()
    while (size > 0 && a[size] > a[(size - 1) / 2]){
        std::swap(a[size], a[(size - 1) / 2]);
        size = (size - 1) / 2;
    }
}

void heapify(std::vector<int> &a, int i) {
    if (2 * i + 1 >= a.size()) return;
    int left = 2 * i + 1;
    int right = left + 1;
    if (right < a.size() && a[left] < a[right] && a[right] > a[i])
    {
        std::swap(a[i], a[right]);
        heapify(a[right]);
    }
}

int main() {
    int N;
    std::cin >> N;
    std::vector<long long> a;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        insert(a, x);
    }

    while (a.size() > 1) {
        int f, s;
        f = a[0]
        std::swap(a[0], a[a.size() - 1]);
        a.pop_back();
        heapify(a, 0);
        s = a[0];
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        heapify(a, 0);
        if(f != s) {
            insert(a, abs(s - f));
        }
    }
    if (a.size()) {
        std::cout << a[0];
    }
    else {
        std::cout << 0;
    }
}