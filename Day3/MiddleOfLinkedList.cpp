#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int data){
        this->val = data;
        next = NULL;
    }

    Node* middleNode(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

};

void printList(Node* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating the linked list 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    // Finding the middle node
    Node* middle = head->middleNode(head);

    if (middle != NULL) {
        cout << "Middle Node Value: " << middle->val << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    return 0;
}

