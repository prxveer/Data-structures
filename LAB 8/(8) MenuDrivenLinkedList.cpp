#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
class LinkedList {
    Node* head = nullptr;
public:
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head}; head = newNode;
        cout << "Inserted " << value << " at the beginning.\n";
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) head = newNode;
        else { Node* temp = head; while (temp->next) temp = temp->next; temp->next = newNode; }
        cout << "Inserted " << value << " at the end.\n";
    }

    void insertBefore(int beforeValue, int value) {
        if (!head) return void(cout << "List is empty.\n");
        if (head->data == beforeValue) return insertAtBeginning(value);
        Node* temp = head; while (temp->next && temp->next->data != beforeValue) temp = temp->next;
        if (temp->next) temp->next = new Node{value, temp->next}, cout << "Inserted " << value << " before " << beforeValue << ".\n";
        else cout << beforeValue << " not found.\n";
    }

    void insertAfter(int afterValue, int value) {
        Node* temp = head; while (temp && temp->data != afterValue) temp = temp->next;
        if (temp) temp->next = new Node{value, temp->next}, cout << "Inserted " << value << " after " << afterValue << ".\n";
        else cout << afterValue << " not found.\n";
    }

    void deleteElement(int value) {
        if (!head) return void(cout << "List is empty.\n");
        if (head->data == value) { Node* toDelete = head; head = head->next; delete toDelete; cout << "Deleted " << value << ".\n"; return; }
        Node* temp = head; while (temp->next && temp->next->data != value) temp = temp->next;
        if (temp->next) { Node* toDelete = temp->next; temp->next = temp->next->next; delete toDelete; cout << "Deleted " << value << ".\n"; }
        else cout << value << " not found.\n";
    }

    void printList() {
        if (!head) return void(cout << "List is empty.\n");
        cout << "List: "; for (Node* temp = head; temp; temp = temp->next) cout << temp->data << " "; cout << endl;
    }
};

int main() {
    LinkedList list; int choice, value, target;
    do {
        cout << "\nMenu:\n1. Insert at the beginning\n2. Insert at the end\n3. Insert before\n4. Insert after\n5. Delete\n6. Print list\n0. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) { cout << "Enter value: "; cin >> value; list.insertAtBeginning(value); }
        else if (choice == 2) { cout << "Enter value: "; cin >> value; list.insertAtEnd(value); }
        else if (choice == 3) { cout << "Enter value and target: "; cin >> value >> target; list.insertBefore(target, value); }
        else if (choice == 4) { cout << "Enter value and target: "; cin >> value >> target; list.insertAfter(target, value); }
        else if (choice == 5) { cout << "Enter value to delete: "; cin >> value; list.deleteElement(value); }
        else if (choice == 6) list.printList();
    } while (choice != 0);
    return 0;
}
