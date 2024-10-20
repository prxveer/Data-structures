#include <iostream>

#define MAX 100

using namespace std;

class Stack {
private:
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(char c) {
        if (top >= MAX - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (top < 0) {
            cout << "Stack underflow" << endl;
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (top < 0) {
            return '\0';
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

void reverseString(char* str, int length) {
    int start = 0, end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    Stack st;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix[j++] = st.pop();
            }
            st.pop();
        } else if (isOperator(c)) {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c)) {
                postfix[j++] = st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty()) {
        postfix[j++] = st.pop();
    }

    postfix[j] = '\0';
}

void infixToPrefix(char* infix, char* prefix) {
    int length = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        length++;
    }

    reverseString(infix, length);

    for (int i = 0; i < length; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    char postfix[MAX];
    infixToPostfix(infix, postfix);
    reverseString(postfix, length);

    for (int i = 0; i < length; i++) {
        prefix[i] = postfix[i];
    }

    prefix[length] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    cout << "Postfix Expression: " << postfix << endl;
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
