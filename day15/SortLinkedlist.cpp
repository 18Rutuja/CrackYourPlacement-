#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

using namespace std;

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
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;

        vector<int> values;
        ListNode* temp = head;

        // Collect all values
        while (temp != nullptr) {
            values.push_back(temp->val);
            temp = temp->next;
        }

        // Sort the collected values
        sort(values.begin(), values.end());

        // Create a new sorted list
        ListNode* sortedHead = new ListNode(values[0]);  // Start with the first sorted value
        ListNode* current = sortedHead;

        for (size_t i = 1; i < values.size(); ++i) {  // Insert the rest of the values
            current->next = new ListNode(values[i]);
            current = current->next;
        }

        return sortedHead;  // Return the new sorted list
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a list from vector
ListNode* createList(const vector<int>& nums) {
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

    // Create a list from vector
    vector<int> nums = {4, 2, 1, 3}; // Example unsorted list
    ListNode* head = createList(nums);

    // Print the original list
    cout << "Original list: ";
    printList(head);

    // Sort the list
    ListNode* sortedHead = solution.sortList(head);

    // Print the sorted list
    cout << "Sorted list: ";
    printList(sortedHead);

    return 0;
}
