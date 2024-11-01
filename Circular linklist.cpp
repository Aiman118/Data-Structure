#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularQueue {
private:
    Node* rear;

public:
    CircularQueue() {
        rear = nullptr;
    }

    bool isEmpty() {
        return rear == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            rear = newNode;
            newNode->next = newNode;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        Node* temp = rear->next;
        int value = temp->data;
        if (rear == temp) { // Single node
            rear = nullptr;
        } else {
            rear->next = temp->next;
        }
        delete temp;
        return value;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = rear->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != rear->next);
        cout << endl;
    }
};

int main() {
    CircularQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    queue.display();

    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;


    queue.display();

    queue.enqueue(50);
    queue.enqueue(60);

    queue.display();

    return 0;
}