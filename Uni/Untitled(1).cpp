//Infix to postfix using standard algorithm for multi digit input
#include <iostream>

using namespace std;

#define MAX 100


class Stack {
private:
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(char c) {
        if (top < MAX - 1) {
            arr[++top] = c;
        }
    }

    char pop() {
        if (top >= 0)
            return arr[top--];
        return '\0';
    }

    char peek() {
        if (top >= 0)
            return arr[top];
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};


bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}


int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return -1;
}


bool isDigit(char c) {
    return c >= '0' && c <= '9';
}


void infixToPostfix(const char* infix, char* postfix) {
    Stack st;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];


        if (isDigit(c)) {
            while (isDigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            i--;
        }

        else if (c == '(') {
            st.push(c);
        }

        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix[j++] = st.pop();
                postfix[j++] = ' ';
            }
            st.pop();
        }

        else if (isOperator(c)) {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c)) {
                postfix[j++] = st.pop();
                postfix[j++] = ' ';
            }
            st.push(c);
        }
    }


    while (!st.isEmpty()) {
        postfix[j++] = st.pop();
        postfix[j++] = ' ';
    }

    postfix[j - 1] = '\0';
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    cout << "Enter infix expression: ";
    cin.getline(infix, MAX);

    infixToPostfix(infix, postfix);

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}


//Singly linked list, user inputs data. Then inputs an element to be deleted. Delete the last occurrence of the element in the list. Print list before and after deletion.
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};


void insert(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void deleteLastOccurrence(Node*& head, int key) {
    Node *lastOccurrence = nullptr, *lastOccurrencePrev = nullptr;
    Node *temp = head, *prev = nullptr;


    while (temp != nullptr) {
        if (temp->data == key) {
            lastOccurrence = temp;
            lastOccurrencePrev = prev;
        }
        prev = temp;
        temp = temp->next;
    }


    if (lastOccurrence != nullptr) {
        if (lastOccurrencePrev != nullptr) {
            lastOccurrencePrev->next = lastOccurrence->next;
        } else {

            head = head->next;
        }
        delete lastOccurrence;
    }
}

int main() {
    Node* head = nullptr;
    int n, element, deleteElement;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> element;
        insert(head, element);
    }

    cout << "List before deletion: ";
    printList(head);

    cout << "Enter the element to delete (last occurrence): ";
    cin >> deleteElement;

    deleteLastOccurrence(head, deleteElement);

    cout << "List after deletion: ";
    printList(head);

    return 0;
}

//ArrayToLL
#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}


Node* arrayToLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;


    Node* head = createNode(arr[0]);
    Node* current = head;


    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    return head;
}


void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);


    Node* head = arrayToLinkedList(arr, size);


    cout << "Linked List: ";
    printLinkedList(head);

    return 0;
}

//traversal,len,search
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void traverseLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int lengthOfLinkedList(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

bool searchInLinkedList(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main() {
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    cout << "Linked List: ";
    traverseLinkedList(head);

    int length = lengthOfLinkedList(head);
    cout << "Length of Linked List: " << length << endl;

    int key = 30;
    if (searchInLinkedList(head, key)) {
        cout << "Element " << key << " found in the linked list." << endl;
    } else {
        cout << "Element " << key << " not found in the linked list." << endl;
    }

    return 0;
}

//list delete
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(12);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(3);

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = deleteHead(head);

    cout << "Linked List after deleting head: ";
    printLinkedList(head);

    return 0;
}

ww

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
};

struct SLLNode {
    int data;
    SLLNode* next;

    SLLNode(int data1) {
        data = data1;
        next = nullptr;
    }
};

// ----- Array to Doubly Linked List (DLL) -----
Node* convertArrToDLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

// ----- Print Doubly Linked List (DLL) -----
void printDLL(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ----- Delete Head in Doubly Linked List (DLL) -----
Node* deleteHeadDLL(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) head->back = nullptr;
    delete temp;
    return head;
}

// ----- Delete Tail in Doubly Linked List (DLL) -----
Node* deleteTailDLL(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->back->next = nullptr;
    delete temp;
    return head;
}

// ----- Delete Kth Node in Doubly Linked List (DLL) -----
Node* deleteKthDLL(Node* head, int k) {
    if (k == 1) return deleteHeadDLL(head);
    Node* current = head;
    for (int i = 1; i < k && current != nullptr; i++) {
        current = current->next;
    }
    if (current == nullptr) return head;
    if (current->next != nullptr) current->next->back = current->back;
    if (current->back != nullptr) current->back->next = current->next;
    delete current;
    return head;
}

// ----- Insert Node Before Head in Doubly Linked List (DLL) -----
Node* insertBeforeHeadDLL(Node* head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    if (head != nullptr) head->back = newNode;
    return newNode;
}

// ----- Insert Node Before Tail in Doubly Linked List (DLL) -----
Node* insertBeforeTailDLL(Node* head, int data) {
    if (head == nullptr) return new Node(data);
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    Node* newNode = new Node(data);
    newNode->back = temp->back;
    newNode->next = temp;
    temp->back = newNode;
    if (temp == head) return newNode;  // if list had only one element
    return head;
}

// ----- Array to Singly Linked List (SLL) -----
SLLNode* convertArrToSLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    SLLNode* head = new SLLNode(arr[0]);
    SLLNode* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new SLLNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// ----- Print Singly Linked List (SLL) -----
void printSLL(SLLNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ----- Delete Head in Singly Linked List (SLL) -----
SLLNode* deleteHeadSLL(SLLNode* head) {
    if (head == nullptr) return nullptr;
    SLLNode* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// ----- Delete Tail in Singly Linked List (SLL) -----
SLLNode* deleteTailSLL(SLLNode* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }
    SLLNode* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// ----- Delete Kth Node in Singly Linked List (SLL) -----
SLLNode* deleteKthSLL(SLLNode* head, int k) {
    if (k == 1) return deleteHeadSLL(head);
    SLLNode* temp = head;
    for (int i = 1; i < k - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) return head;
    SLLNode* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
    return head;
}

// Main function demonstrating DLL and SLL operations
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Doubly Linked List Operations:" << endl;
    Node* dllHead = convertArrToDLL(arr);
    printDLL(dllHead);
    dllHead = deleteHeadDLL(dllHead);
    printDLL(dllHead);
    dllHead = deleteTailDLL(dllHead);
    printDLL(dllHead);

    cout << "Singly Linked List Operations:" << endl;
    SLLNode* sllHead = convertArrToSLL(arr);
    printSLL(sllHead);
    sllHead = deleteHeadSLL(sllHead);
    printSLL(sllHead);
    sllHead = deleteTailSLL(sllHead);
    printSLL(sllHead);

    return 0;
}

