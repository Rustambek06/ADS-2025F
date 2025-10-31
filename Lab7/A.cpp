#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void merge(std::vector<std::string>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<std::string> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    } 
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i].size() < R[j].size() || L[i].size() == R[j].size()) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<std::string>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {

    int T;
    std::cin >> T;
    std::cin.ignore();
    while(T--) {
        std::vector<std::string> arr;
        std::string input;
        std::getline(std::cin, input);
        std::istringstream iss(input);
        std::string word;
        while (iss >> word) {
            arr.push_back(word);
        }

        int n = arr.size();

        mergeSort(arr, 0, n - 1);
        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
}