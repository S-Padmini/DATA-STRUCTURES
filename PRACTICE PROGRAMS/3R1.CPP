#include <iostream>
using namespace std;
// Definition of the Node class
class Node {
public:
string data; // Data stored in the node
Node* next; // Pointer to the next node in the list
};
// Function to insert a new node at a specific position in the list
Node* insertAtPosition(Node* head, string new_data, int position) {
Node* new_node = new Node(); // Allocate new node
new_node->data = new_data; // Assign data to the new node
if (position == 0) {
// If inserting at the head
new_node->next = head;
return new_node;
}
Node* temp = head;
for (int i = 0; temp != NULL && i < position - 1; i++) {
temp = temp->next; // Traverse to the position
}
if (temp == NULL) {
// If position is out of range
cout << "Position out of range\n";
delete new_node;
return head;
}
new_node->next = temp->next;
temp->next = new_node;
return head;
}
// Function to delete the node at a specific position in the list
Node* deleteAtPosition(Node* head, int position) {
if (head == NULL) return NULL;
if (position == 0) {
// If deleting the head
Node* temp = head;
head = head->next;
delete temp;
return head;
}
Node* temp = head;
for (int i = 0; temp != NULL && i < position - 1; i++) {
temp = temp->next; // Traverse to the position
}
if (temp == NULL || temp->next == NULL) {
// If position is out of range
cout << "Position out of range\n";
return head;
}
Node* next = temp->next->next;
delete temp->next;
temp->next = next;
return head;
}
// Function to print the linked list
void printList(Node* head) {
Node* temp = head;
while (temp != NULL) {
cout << temp->data << "\n";
temp = temp->next;
}
}
// Main function to test the linked list operations
int main() {
Node* head = NULL;
// Insert nodes at the front
head = insertAtPosition(head, "KRITHICK", 0);
head = insertAtPosition(head, "ABIJITH", 0);
head = insertAtPosition(head, "RAFEEK", 0);
cout << "\n\nLinked list after inserting at front:\n";
printList(head);
// Insert node at position 2
head = insertAtPosition(head, "AMIT", 2);
cout << "\n\nLinked list after inserting at position 2:\n";
printList(head);
// Delete node at position 1
head = deleteAtPosition(head, 1);
cout << "\n\nLinked list after deleting at position 1:\n";
printList(head);
return 0;
}
