#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int data) {
        this->val = data;
        this->next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    bool LLCycle() {
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    Node* middleNode() {
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtTail(val);
    }

    cout << "Original List: ";
    list.printList();

    // Finding the middle node
    Node* middle = list.middleNode();
    if (middle != NULL) {
        cout << "Middle Node Value: " << middle->val << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    cout << "Detect cycle in ll" << endl;
    if (list.LLCycle()) {
        cout << "Cycle present in linked list" << endl;
    } else {
        cout << "Cycle is not present" << endl;
    }

    return 0;
}
