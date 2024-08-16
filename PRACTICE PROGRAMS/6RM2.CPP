#include <iostream>
#include <stack>

using namespace std;

class Deque {
private:
    stack<int> frontStack; // Stack to manage front operations
    stack<int> rearStack;  // Stack to manage rear operations

    void transferFrontToRear() {
        while (!frontStack.empty()) {
            rearStack.push(frontStack.top());
            frontStack.pop();
        }
    }

    void transferRearToFront() {
        while (!rearStack.empty()) {
            frontStack.push(rearStack.top());
            rearStack.pop();
        }
    }

public:
    // Insert item x on the front end of the deque
    void push(int x) {
        frontStack.push(x);
    }

    // Remove the front item from the deque and return it
    int pop() {
        if (frontStack.empty()) {
            transferRearToFront();
        }
        if (frontStack.empty()) {
            throw runtime_error("Deque is empty");
        }
        int value = frontStack.top();
        frontStack.pop();
        return value;
    }

    // Insert item x on the rear end of the deque
    void inject(int x) {
        rearStack.push(x);
    }

    // Remove the rear item from the deque and return it
    int eject() {
        if (rearStack.empty()) {
            transferFrontToRear();
        }
        if (rearStack.empty()) {
            throw runtime_error("Deque is empty");
        }
        int value = rearStack.top();
        rearStack.pop();
        return value;
    }
};

int main() {
    Deque dq;

    dq.push(10);
    dq.push(20);
    dq.inject(30);
    dq.inject(40);

    cout << "Popped from front: " << dq.pop() << endl; // Should be 20
    cout << "Ejected from rear: " << dq.eject() << endl; // Should be 40
    cout << "Popped from front: " << dq.pop() << endl; // Should be 10
    cout << "Ejected from rear: " << dq.eject() << endl; // Should be 30

    return 0;
}
