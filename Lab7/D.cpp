#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

// GPA шкала
map<string, double> gradeMap = {
    {"A+", 4.00}, {"A", 3.75}, {"B+", 3.50}, {"B", 3.00},
    {"C+", 2.50}, {"C", 2.00}, {"D+", 1.50}, {"D", 1.00}, {"F", 0.00}
};

// Структура студента
struct Student {
    string lastname;
    string firstname;
    double gpa;
};

// Сравнение для сортировки
bool compare(const Student& a, const Student& b) {
    if (a.gpa != b.gpa) return a.gpa < b.gpa;
    if (a.lastname != b.lastname) return a.lastname < b.lastname;
    return a.firstname < b.firstname;
}

// Merge-функция
void merge(vector<Student>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Student> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j])) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// MergeSort
void mergeSort(vector<Student>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n;
    cin >> n;
    vector<Student> students;

    for (int i = 0; i < n; ++i) {
        string lastname, firstname;
        int m;
        cin >> lastname >> firstname >> m;

        vector<pair<string, int>> subjects(m);
        double totalPoints = 0;
        int totalCredits = 0;

        for (int j = 0; j < m; ++j) {
            string mark;
            int credits;
            cin >> mark >> credits;
            subjects[j] = {mark, credits};
            totalPoints += gradeMap[mark] * credits;
            totalCredits += credits;
        }

        double gpa = totalPoints / totalCredits;
        students.push_back({lastname, firstname, gpa});
    }

    mergeSort(students, 0, n - 1);

    for (const auto& s : students) {
        cout << s.lastname << " " << s.firstname << " " << fixed << setprecision(3) << s.gpa << endl;
    }

    return 0;
}
