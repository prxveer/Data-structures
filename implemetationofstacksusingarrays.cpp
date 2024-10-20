#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100]; 
    int top;       

public:
    Stack() {
        top = -1;  
    }

    void push(int x) {
        if (top == 99) { 
            cout << "Error: Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;  
        cout << x << " pushed into the stack" << endl;
    }

    int pop() {
        if (top == -1) { 
            cout << "Error: Stack Underflow" << endl;
            return -1;
        }
        int popped = arr[top];  
        top--;                 
        return popped;
    }

 
    int peek() {
        if (top == -1) {  
            cout << "Error: Stack Underflow" << endl;
            return -1;
        }
        return arr[top]; 
    }


    bool isEmpty() {
        return top == -1; 
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " popped from the stack" << endl;
    cout << "Top element is " << s.peek() << endl;
    cout << "Stack empty? " << s.isEmpty() << endl;
    return 0;
}
