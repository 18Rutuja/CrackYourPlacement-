#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* temp = head;
        int i = 1;
        ListNode *l, *r, *prev = nullptr, *next = nullptr;
        while (i < left) {
            prev = temp;
            temp = temp->next;
            i++;
        }
        l = temp;
        while (i < right) {
            temp = temp->next;
            i++;
        }
        r = temp;
        if (temp->next) {
            next = temp->next;
        }
        if (prev != nullptr) {
            prev->next = r;
        } else {
            head = r;
        }
        temp = l;
        while (temp != next) {
            ListNode* curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        l->next = next;
        return head;
    }  
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to create a list from vector
ListNode* createList(const std::vector<int>& nums) {
    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy->next;
}

int main() {
    Solution solution;

    // Create list from vector
    std::vector<int> nums = {1, 2, 3, 4, 5};
    ListNode* head = createList(nums);

    // Set left and right positions
    int left = 2, right = 4;

    // Print original list
    std::cout << "Original list: ";
    printList(head);

    // Reverse the sublist
    ListNode* result = solution.reverseBetween(head, left, right);

    // Print the result
    std::cout << "Reversed list: ";
    printList(result);

    return 0;
}
