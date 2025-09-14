#include <iostream>
#include <string>

struct Node {
    int num;
    Node* next;
    Node(const int& n): num(n), next(nullptr) {}
};

Node* everySecond(Node* head) {
    if (!head) return nullptr; // нет второго элемента

    Node* curr = head;
    while (curr && curr->next) {
        curr->next = curr->next->next;
        curr = curr->next;
    }

    return head;
}

int main() {
    
    int n;
    std::cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        Node* node = new Node(num);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    head = everySecond(head);
    Node* curr = head;
    while(curr) {
        std::cout << curr->num << " ";
        curr = curr->next;
    }

    return 0;
}