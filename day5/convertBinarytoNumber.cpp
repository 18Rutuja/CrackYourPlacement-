#include <iostream>
#include <bitset>
#include <string>
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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        string binary = "";

        while (temp != nullptr) {
            binary.push_back(temp->val + '0'); // Convert integer 0 or 1 to character '0' or '1'
            temp = temp->next;
        }

        // Convert binary string to decimal using bitset
        bitset<32> bits(binary);
        return bits.to_ulong();
    }
};

int main() {
    // Example usage:
    ListNode* node3 = new ListNode(1);
    ListNode* node2 = new ListNode(0, node3);
    ListNode* node1 = new ListNode(1, node2);

    Solution sol;
    cout << "Decimal value: " << sol.getDecimalValue(node1) << endl;

    delete node1;
    delete node2;
    delete node3;

    return 0;
}
