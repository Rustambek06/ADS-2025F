#include <iostream>

struct Node {
    int num;
    Node* next;
    Node(const int& n) : num(n), next(nullptr) {}
};

Node* insertion(Node* head, int num, int position) {
    if (position == 0) {
        Node* newHead = new Node(num);
        newHead->next = head;
        return newHead;
    }

    Node* curr = head;
    int count = 0;

    while (curr && count < position - 1) {
        curr = curr->next;
        count++;
    }

    if (!curr) {
        return head;
    }

    Node* newNode = new Node(num);
    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        std::cout << curr->num << " ";
        curr = curr->next;
    }
    std::cout << "\n";
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

    int data, position;
    std::cin >> data >> position;

    head = insertion(head, data, position);

    printList(head);

    return 0;
}
