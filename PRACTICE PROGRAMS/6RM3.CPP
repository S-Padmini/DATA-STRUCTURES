#include <iostream>
#include <queue>
using namespace std;

void generateBinaryNumbers(int N) {
    // Create an empty queue of strings
    queue<string> q;

    // Enqueue the first binary number
    q.push("1");

    // Loop until we generate N binary numbers
    for (int i = 0; i < N; i++) {
        // Print the front of the queue
        string binary = q.front();
        cout << binary << endl;
        q.pop(); // Remove the front of the queue

        // Append "0" to the current binary number and enqueue it
        q.push(binary + "0");

        // Append "1" to the current binary number and enqueue it
        q.push(binary + "1");
    }
}

int main() {
    int N;
    cout << "Enter a number: ";
    cin >> N;
    generateBinaryNumbers(N);
    return 0;
}
