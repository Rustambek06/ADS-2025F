#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> result(N);
    result[0] = -1;

    for (int i = 1; i < N; i++) {
        result[i] = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] <= a[i]) {
                result[i] = a[j];
                break;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
}
