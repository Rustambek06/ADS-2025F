#include <iostream>
#include <string>

struct Node {
    std::string word;
    Node* next;
    Node(const std::string& w) : word(w), next(nullptr) {}
};

// функция сдвига на k
Node* shift(Node* head, int n, int k) {
    if (!head || k % n == 0) return head; // нет сдвига
    k %= n;

    // 1. находим хвост
    Node* tail = head;
    for (int i = 1; i < n; i++) {
        tail = tail->next;
    }

    // 2. делаем цикл
    tail->next = head;

    // 3. идём к новой голове
    Node* newTail = head;
    for (int i = 1; i < k; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = nullptr; // разрываем цикл

    return newHead;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    // создаём список
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        std::string w;
        std::cin >> w;
        Node* node = new Node(w);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    // сдвигаем
    head = shift(head, n, k);

    // выводим результат
    Node* curr = head;
    while (curr) {
        std::cout << curr->word << " ";
        curr = curr->next;
    }

    return 0;
}
