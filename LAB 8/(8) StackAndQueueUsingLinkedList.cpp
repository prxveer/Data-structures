#include <iostream>
#include <stack>
#include <list>
using namespace std;

// Stack Implementation using STL stack
class Stack {
    stack<int> stk;  // Using STL stack for Stack implementation

public:
    void push(int value) {
        stk.push(value);  // Push onto the stack
        cout << "Pushed " << value << " onto the stack.\n";
    }

    void pop() {
        if (stk.empty()) {
            cout << "Stack Underflow\n";
        } else {
            cout << "Popped " << stk.top() << " from the stack.\n";
            stk.pop();  // Remove the top element
        }
    }

    void display() {
        if (stk.empty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Stack (Top to Bottom): ";
            stack<int> temp = stk;  // Copy stack to display without modifying it
            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
        }
    }
};

// Queue Implementation using STL list
class Queue {
    list<int> lst;  // Using STL list for Queue implementation

public:
    void enqueue(int value) {
        lst.push_back(value);  // Insert at the end
        cout << "Enqueued " << value << " to the queue.\n";
    }

    void dequeue() {
        if (lst.empty()) {
            cout << "Queue Underflow\n";
        } else {
            cout << "Dequeued " << lst.front() << " from the queue.\n";
            lst.pop_front();  // Remove from the front
        }
    }

    void display() {
        if (lst.empty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Queue (Front to Rear): ";
            for (int x : lst) cout << x << " ";
            cout << endl;
        }
    }
};

// Main function to test both Stack and Queue
int main() {
    Stack stack;
    Queue queue;

    // Testing Stack
    cout << "Stack Operations:\n";
    stack.push(10);
    stack.push(20);
    stack.display();
    stack.pop();
    stack.display();

    // Testing Queue
    cout << "\nQueue Operations:\n";
    queue.enqueue(30);
    queue.enqueue(40);
    queue.display();
    queue.dequeue();
    queue.display();

    return 0;
}
