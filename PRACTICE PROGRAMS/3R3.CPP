//Program of find middle of double linked list
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;
};
void push(Node** head,int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    if (*head == NULL) {
        *head = new_node;
    }
    else {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }
}
Node* middle_element(Node* head) {
    if (head == NULL)
        return NULL;

    Node* t1 = head;
    Node* t2 = head;

    while (t2 != NULL && t2->next != NULL) {
        t1 = t1->next;
        t2 = t2->next->next;
    }
    return t1;
}
void print(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
    cout<<"\n";
}
int main() {
    Node* head = NULL;
    push(&head, 11);
    push(&head, 52);
    push(&head, 93);
    push(&head, 55);
    push(&head, 15);
    print(head);

    Node* result = middle_element
    (head);
    if (result != NULL)
        cout << "Middle of the Doubly Linked List: " << result->data << endl;
    else
        cout << "The list is empty." << endl;
    return 0;
}


