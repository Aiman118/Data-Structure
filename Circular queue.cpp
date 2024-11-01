#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;       
    int front;      
    int rear;       
    int size;     
    int count;    

public:
  
    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
        count = 0;
    }


    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }

        if (front == -1) { 
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
        count++;
        cout << "Enqueued: " << value << endl;
    }

    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue" << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        count--;
    }

   
    bool isEmpty() {
        return count == 0;
    }

  
    bool isFull() {
        return count == size;
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        int i = front;
        cout << "Queue elements: ";
        do {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout << endl;
    }

    
    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    queue.display();  

    queue.dequeue();
    queue.dequeue();
    queue.display();  

    queue.enqueue(60);
    queue.enqueue(70);
    queue.display();  

    queue.dequeue();
    queue.display();  
    return 0;
}