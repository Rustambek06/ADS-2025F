#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> L(n);
    for (int i = 0; i < n; i++) {
        std::cin >> L[i];
    }

    int m;
    std::cin >> m;
    std::vector<int> R(m);
    for (int i = 0; i < m; i++) {
        std::cin >> R[i];
    }

    int arr[n + m];
    
    int i = 0, j = 0;
    int k = 0;

    while (i < n && j < m) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < m) {
        arr[k] = R[j];
        j++;
        k++;
    }

    for (int i = 0; i < n + m; i++) {
        std::cout << arr[i] << " ";
    }
}