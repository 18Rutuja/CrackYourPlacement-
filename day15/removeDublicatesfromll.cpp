#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution class with deleteDuplicates function
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ans = head;
        while(ans && ans->next){
            if(ans->val == ans->next->val) ans->next = ans->next->next;
            else ans = ans->next;
        }
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
    // Create linked list: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);

    Solution sol;
    cout << "Original list: ";
    printList(head);

    // Remove duplicates
    head = sol.deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
