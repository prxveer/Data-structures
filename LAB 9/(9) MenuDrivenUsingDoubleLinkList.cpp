#include <iostream>
using namespace std;

class DoublyLinkedList {
    struct Node { int data; Node *prev, *next; Node(int value) : data(value), prev(nullptr), next(nullptr) {} };
    Node *head;
public:
    DoublyLinkedList() : head(nullptr) {}
    ~DoublyLinkedList() { while (head) deleteFromEnd(); }

    void insertAtEnd(int data) {
        Node *newNode = new Node(data);
        if (!head) { head = newNode; return; }
        Node *temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode; newNode->prev = temp;
    }

    void deleteFromEnd() {
        if (!head) { cout << "List is empty" << endl; return; }
        if (!head->next) { delete head; head = nullptr; return; }
        Node *temp = head;
        while (temp->next) temp = temp->next;
        temp->prev->next = nullptr; delete temp;
    }

    void insertAtPosition(int data, int pos) {
        if (pos < 1) { cout << "Position out of range" << endl; return; }
        Node *newNode = new Node(data);
        if (pos == 1) { newNode->next = head; if (head) head->prev = newNode; head = newNode; return; }
        Node *temp = head;
        for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
        if (!temp) { cout << "Position out of range" << endl; delete newNode; return; }
        newNode->next = temp->next; newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode; temp->next = newNode;
    }

    void deleteFromPosition(int pos) {
        if (!head || pos < 1) { cout << "Position out of range" << endl; return; }
        Node *temp = head;
        if (pos == 1) { head = temp->next; if (head) head->prev = nullptr; delete temp; return; }
        for (int i = 1; temp && i < pos; i++) temp = temp->next;
        if (!temp) { cout << "Position out of range" << endl; return; }
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev; delete temp;
    }

    void insertAfter(int target, int data) {
        Node *temp = head;
        while (temp && temp->data != target) temp = temp->next;
        if (!temp) { cout << "Target element not found" << endl; return; }
        Node *newNode = new Node(data); newNode->next = temp->next; newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode; temp->next = newNode;
    }

    void insertBefore(int target, int data) {
        if (!head) { cout << "List is empty" << endl; return; }
        if (head->data == target) { insertAtPosition(data, 1); return; }
        Node *temp = head;
        while (temp && temp->data != target) temp = temp->next;
        if (!temp) { cout << "Target element not found" << endl; return; }
        Node *newNode = new Node(data); newNode->next = temp; newNode->prev = temp->prev;
        if (temp->prev) temp->prev->next = newNode; temp->prev = newNode;
        if (temp == head) head = newNode;
    }

    void printList() const {
        if (!head) { cout << "List is empty." << endl; return; }
        for (Node *curr = head; curr; curr = curr->next) cout << curr->data << " ";
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list; int choice, data, position, target;
    while (true) {
        cout << "\nMenu:\n1. Insert at end\n2. Delete from end\n3. Insert at position\n4. Delete from position\n5. Insert after\n6. Insert before\n7. Print list\n8. Exit\n";
        cout << "Enter your choice: "; cin >> choice;
        switch (choice) {
            case 1: cout << "Enter data: "; cin >> data; list.insertAtEnd(data); break;
            case 2: list.deleteFromEnd(); break;
            case 3: cout << "Enter position: "; cin >> position; cout << "Enter data: "; cin >> data; list.insertAtPosition(data, position); break;
            case 4: cout << "Enter position: "; cin >> position; list.deleteFromPosition(position); break;
            case 5: cout << "Enter target element: "; cin >> target; cout << "Enter data: "; cin >> data; list.insertAfter(target, data); break;
            case 6: cout << "Enter target element: "; cin >> target; cout << "Enter data: "; cin >> data; list.insertBefore(target, data); break;
            case 7: list.printList(); break;
            case 8: return 0;
            default: cout << "Invalid choice. Please try again.\n";
        }
    }
}
