#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextt = NULL;

        while(curr){
           nextt = curr -> next;
           curr -> next = prev;
           prev = curr;
           curr = nextt;  
                   
        }
       
        return prev;
    }
};

int main(){
    
}