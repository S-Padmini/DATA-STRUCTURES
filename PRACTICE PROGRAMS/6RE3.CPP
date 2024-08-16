//implement a circular queue using arrays

#include<iostream>
using namespace std;

class Q {
    int* q;
    int n;
    int Front;
    int rear;

public:
    Q(int size) {
        n = size;
        q = new int[n];
        Front = -1;
        rear = -1;
    }

    void enqueue(int element) {
        if ((rear + 1) % n == Front) {
            cout << "Overflow" << endl;
            return;
        }
        if (Front == -1) {
            Front = rear = 0;
        } else {
            rear = (rear + 1) % n;
        }
        q[rear] = element;
    }

    int dequeue() {
        if (Front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int element = q[Front];
        if (Front == rear) {
            Front = rear = -1;
        } else {
            Front = (Front + 1) % n;
        }
        return element;
    }
};

int main() {
    Q q1(5); // Specify the size of the queue
    q1.enqueue(40);
    q1.enqueue(30);
    cout << q1.dequeue() << endl;
    return 0;
}
