#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

class Solution {
  public:
    long long multiplyTwoLists(Node* first, Node* second) {
        string f1 = "";
        string f2 = "";
        
        while (first != NULL || second != NULL) {
            if (first) {
                f1 += (char)(first->data + '0');
                first = first->next;
            }
            if (second) {
                f2 += (char)(second->data + '0');
                second = second->next;
            }
        }
        
        long long firstS = stoll(f1);
        long long secondS = stoll(f2);
        
        long long N = 1000000007;
        return (firstS % N) * (secondS % N) % N;
    }
};

// Utility functions to create a new node and to print the list
struct Node* newNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data;
        if (node->next) cout << "->";
        node = node->next;
    }
    cout << "\n";
}

int main() {
    struct Node* first = NULL;
    struct Node* second = NULL;
    
    // create first list 9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    printf("First List is: ");
    printList(first);
    
    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is: ");
    printList(second);
    
    // Multiply the two lists and see result
    Solution sol;
    cout << "Result is: ";
    cout << sol.multiplyTwoLists(first, second) << endl;
    
    return 0;
}
