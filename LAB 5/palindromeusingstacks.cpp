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

bool isPalindrome(const char* str) {
    Stack stack;
    int length = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }

    for (int i = 0; i < length / 2; i++) {
        stack.push(str[i]);
    }

    int start = (length % 2 == 0) ? length / 2 : (length / 2) + 1;

    for (int i = start; i < length; i++) {
        if (stack.pop() != str[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    char str[MAX];

    cout << "Enter a string: ";
    cin.getline(str, MAX);

    if (isPalindrome(str)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
