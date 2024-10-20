#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear, size;
    int* queue;

public:
    CircularQueue(int s) {
        front = rear = -1;
        size = s;
        queue = new int[s];
    }

    void insert(int data) {
        if ((rear + 1) % size == front) {
            cout << "Queue is full" << endl;
        } else if (front == -1) {
            front = rear = 0;
            queue[rear] = data;
        } else {
            rear = (rear + 1) % size;
            queue[rear] = data;
        }
    }

    int deleteElement() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        } else if (front == rear) {
            int temp = queue[front];
            front = rear = -1;
            return temp;
        } else {
            int temp = queue[front];
            front = (front + 1) % size;
            return temp;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
        } else if (rear >= front) {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++)
                cout << queue[i] << " ";
            cout << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i < size; i++)
                cout << queue[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << queue[i] << " ";
            cout << endl;
        }
    }

    ~CircularQueue() {
        delete[] queue;
    }
};

int main() {
    CircularQueue cq(5);
    cq.insert(1);
    cq.insert(2);
    cq.insert(3);
    cq.display();
    cout << "Deleted element: " << cq.deleteElement() << endl;
    cq.display();
    cq.insert(4);
    cq.insert(5);
    cq.insert(6);
    cq.display();
    return 0;
}

