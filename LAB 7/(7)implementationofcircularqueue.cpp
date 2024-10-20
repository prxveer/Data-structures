#include <iostream>
#include <string>
#define SIZE 5

using namespace std;

class CircularQueue {
private:
    string items[SIZE];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear + 1) % SIZE == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enQueue(const string& value) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        
        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        items[rear] = value;
        cout << "Inserted: " << value << endl;
    }

    string deQueue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return "";
        }

        string deletedValue = items[front];

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }

        return deletedValue;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Circular Queue: ";
        int i = front;

        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enQueue("Hello");
    q.enQueue("World");
    q.display();

    string deletedValue = q.deQueue();
    if (!deletedValue.empty()) {
        cout << "Deleted: " << deletedValue << endl;
    }

    q.display();

    q.enQueue("Circular");
    q.enQueue("Queue");
    q.enQueue("Example");
    
    q.display();

    return 0;
}
