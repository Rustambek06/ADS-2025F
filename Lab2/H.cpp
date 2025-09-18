#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

Node* insert(Node* head, Node* node, int position){
    if (position == 0){
        node->next = head;
        return node;
    }

    Node* curr = head;
    int count = 0;
    while (curr && count < position - 1) {
        curr = curr->next;
        count++;
    }

    node->next = curr->next;
    curr->next = node;

    return head;
}

Node* remove(Node* head, int position){
    if (!head) return nullptr;
    
    if (position == 0) {
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }

    Node* curr = head;
    int count = 0;
    while(curr && count < position - 1) {
        curr = curr->next; 
        count++;
    }

    if (curr && curr->next) {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }

    return head;
}

Node* replace(Node* head, int p1, int p2){
    if (!head) return nullptr;

    // Step 1: extract node at p1
    Node* prev1 = nullptr;
    Node* node1 = head;
    for (int i = 0; i < p1; i++) {
        prev1 = node1;
        node1 = node1->next;
    }

    if (prev1) {
        prev1->next = node1->next;
    } else {
        head = node1->next;
    }

    // Step 2: insert node1 at p2
    if (p2 == 0) {
        node1->next = head;
        head = node1;
        return head;
    }

    Node* curr = head;
    for (int i = 0; i < p2 - 1; i++) {
        curr = curr->next;
    }

    node1->next = curr->next;
    curr->next = node1;

    return head;
}

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void print(Node* head){
    if (!head) {
        cout << -1 << endl;
        return;
    }
    Node* curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next) cout << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* cyclic_left(Node* head, int x){
    if (!head || !head->next) return head;

    // find length
    int len = 0;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    len++;

    x = x % len;
    if (x == 0) return head;

    // connect tail to head
    tail->next = head;

    // find new head
    Node* newTail = head;
    for (int i = 0; i < x - 1; i++) {
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}

Node* cyclic_right(Node* head, int x){
    if (!head || !head->next) return head;

    // find length
    int len = 0;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    len++;

    x = x % len;
    if (x == 0) return head;

    // right shift by x = left shift by len-x
    int leftShift = len - x;

    // connect tail to head
    tail->next = head;

    // find new head
    Node* newTail = head;
    for (int i = 0; i < leftShift - 1; i++) {
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}

int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}
