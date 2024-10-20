#include <iostream>

#define MAX 100

using namespace std;

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(int value) {
        if (top >= MAX - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack underflow" << endl;
            return 0;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int evaluatePostfix(char* postfix) {
    Stack st;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int operand2 = st.pop();
            int operand1 = st.pop();
            switch (c) {
                case '+': st.push(operand1 + operand2); break;
                case '-': st.push(operand1 - operand2); break;
                case '*': st.push(operand1 * operand2); break;
                case '/': st.push(operand1 / operand2); break;
                case '^': st.push(pow(operand1, operand2)); break;
            }
        }
    }

    return st.pop();
}

int evaluatePrefix(char* prefix) {
    Stack st;

    int length = 0;
    for (int i = 0; prefix[i] != '\0'; i++) {
        length++;
    }

    for (int i = length - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int operand1 = st.pop();
            int operand2 = st.pop();
            switch (c) {
                case '+': st.push(operand1 + operand2); break;
                case '-': st.push(operand1 - operand2); break;
                case '*': st.push(operand1 * operand2); break;
                case '/': st.push(operand1 / operand2); break;
                case '^': st.push(pow(operand1, operand2)); break;
            }
        }
    }

    return st.pop();
}

int main() {
    char postfix[MAX], prefix[MAX];

    cout << "Enter postfix expression: ";
    cin >> postfix;
    cout << "Postfix evaluation result: " << evaluatePostfix(postfix) << endl;

    cout << "Enter prefix expression: ";
    cin >> prefix;
    cout << "Prefix evaluation result: " << evaluatePrefix(prefix) << endl;

    return 0;
}
