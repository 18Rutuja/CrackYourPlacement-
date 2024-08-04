#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Create two dummy nodes to start the smaller and greater lists
        ListNode* smallerHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);

        // These pointers will be used to construct the new lists
        ListNode* smaller = smallerHead;
        ListNode* greater = greaterHead;

        // Traverse the original list
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val < x) {
                smaller->next = curr;
                smaller = smaller->next;
            } else {
                greater->next = curr;
                greater = greater->next;
            }
            curr = curr->next;
        }

        // Combine the two lists
        greater->next = nullptr; // Important to avoid cycle
        smaller->next = greaterHead->next;

        // The head of the new list is the next node of the dummy smallerHead
        ListNode* newHead = smallerHead->next;

        // Clean up the dummy nodes
        delete smallerHead;
        delete greaterHead;

        return newHead;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a linked list for testing
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;

    Solution solution;
    ListNode* partitionedHead = solution.partition(head, x);

    // Printing the partitioned list
    printList(partitionedHead);

    return 0;
}
