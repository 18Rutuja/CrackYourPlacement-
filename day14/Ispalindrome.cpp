#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
private:
    // Helper function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        // Step 1: Use fast and slow pointers to find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* secondHalfHead = reverseList(slow);

        // Step 3: Compare the first half and the reversed second half
        ListNode* firstHalfHead = head;
        ListNode* secondHalfIter = secondHalfHead;
        bool isPalin = true;
        while (secondHalfIter != nullptr) {
            if (firstHalfHead->val != secondHalfIter->val) {
                isPalin = false;
                break;
            }
            firstHalfHead = firstHalfHead->next;
            secondHalfIter = secondHalfIter->next;
        }

        // Step 4 (Optional): Restore the original list
        reverseList(secondHalfHead);

        return isPalin;
    }
};

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    Solution solution;
    if (solution.isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
