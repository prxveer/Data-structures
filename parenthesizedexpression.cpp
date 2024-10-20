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

    bool isEmpty() {
        return top == -1;
    }
};

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool checkParentheses(const char* expression) {
    Stack stack;

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) {
                return false;
            }
            char lastOpening = stack.pop();
            if (!isMatchingPair(lastOpening, ch)) {
                return false;
            }
        }
    }

    return stack.isEmpty();
}

int main() {
    char expression[MAX];

    cout << "Enter a parenthesized expression: ";
    cin.getline(expression, MAX);

    if (checkParentheses(expression)) {
        cout << "The parentheses are matched." << endl;
    } else {
        cout << "The parentheses are not matched." << endl;
    }

    return 0;
}
