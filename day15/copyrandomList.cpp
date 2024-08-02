#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, Node*> newest;

        Node* curr = head;

        while (curr) {
            newest[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            newest[curr]->next = newest[curr->next];
            newest[curr]->random = newest[curr->random];
            curr = curr->next;
        }

        return newest[head];
    }
};

// Helper function to print the list
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << "Node value: " << curr->val;
        if (curr->random) {
            cout << ", Random points to: " << curr->random->val;
        } else {
            cout << ", Random points to: NULL";
        }
        cout << endl;
        curr = curr->next;
    }
}

int main() {
    // Create a linked list: 1 -> 2 -> 3
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->next = third;

    // Set random pointers
    head->random = third; // 1's random points to 3
    second->random = head; // 2's random points to 1
    third->random = second; // 3's random points to 2

    // Print original list
    cout << "Original list:" << endl;
    printList(head);

    // Copy list
    Solution solution;
    Node* copiedList = solution.copyRandomList(head);

    // Print copied list
    cout << "Copied list:" << endl;
    printList(copiedList);

    return 0;
}
