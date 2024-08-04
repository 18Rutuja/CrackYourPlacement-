#include <iostream>
#include <stack>

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        Node* tail = head;
        std::stack<Node*> stack;
        while(cur != nullptr) {
            if(cur->child != nullptr) {
                Node* child = cur->child;
                if(cur->next != nullptr) { 
                    stack.push(cur->next);
                    cur->next->prev = nullptr; 
                }
                cur->next = child;
                child->prev = cur;
                cur->child = nullptr;
            }
            tail = cur;
            cur = cur->next;
        }
        while(!stack.empty()) {
            cur = stack.top();
            stack.pop();
            tail->next = cur;
            cur->prev = tail;
            while(cur != nullptr) {
                tail = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

// Helper function to print the doubly linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating the linked list with child pointers
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->child = new Node(7);
    head->next->next->child->next = new Node(8);
    head->next->next->child->next->prev = head->next->next->child;

    Solution solution;
    Node* flattenedHead = solution.flatten(head);

    // Printing the flattened list
    printList(flattenedHead);

    return 0;
}
