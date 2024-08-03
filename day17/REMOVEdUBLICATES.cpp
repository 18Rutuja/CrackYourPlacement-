#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int , int> mp;
        ListNode* p = head;

        while(p){
            mp[p->val]++;
            p= p-> next;
        }

        ListNode * head2 = NULL, *tail = NULL;

        for(auto & it : mp){
            if(it.second == 1){
                ListNode *node = new ListNode(it.first);
                if(!head2){
                    head2 = node;
                    tail = head2;
                }else{
                    tail -> next = node;
                    tail = tail -> next;
                }
            }
        }
       return head2;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < size; ++i) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Main function
int main() {
    // Create a sample linked list
    int arr[] = {1, 2, 3, 2, 4, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, size);
    
    // Print the original list
    cout << "Original List: ";
    printList(head);

    // Delete duplicates
    Solution solution;
    ListNode* newHead = solution.deleteDuplicates(head);
    
    // Print the modified list
    cout << "Modified List: ";
    printList(newHead);

    // Clean up memory
    while (newHead != nullptr) {
        ListNode* temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

    return 0;
}
