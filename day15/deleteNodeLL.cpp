#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class with removeElements function
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node to handle edge cases where the head needs to be removed
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp = dummy;
        ListNode* del = nullptr;
        
        while(temp->next != nullptr){
            if(temp->next->val == val) {
                del = temp->next;
                temp->next = temp->next->next;
                delete del;
            } else {
                temp = temp->next;
            }
        }
        
        head = dummy->next;
        delete dummy;  // Clean up the dummy node
        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a new node
ListNode* createNode(int value) {
    return new ListNode(value);
}

// Main function
int main() {
    // Create linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    Solution sol;
    cout << "Original list: ";
    printList(head);

    // Remove elements with value 6
    head = sol.removeElements(head, 6);

    cout << "List after removing elements with value 6: ";
    printList(head);

    return 0;
}
