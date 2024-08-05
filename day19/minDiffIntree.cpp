#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& temp) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left, temp);
        temp.push_back(root->val);
        inorder(root->right, temp);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> temp;
        inorder(root, temp);

        int minDiff = INT_MAX;

        for (int i = 1; i < temp.size(); ++i) {
            minDiff = min(minDiff, temp[i] - temp[i - 1]);
        }

        return minDiff;
    }
};

// Helper function to build a tree for testing
TreeNode* buildTree() {
    cout << "Enter node value (-1 for NULL): ";
    int value;
    cin >> value;

    if (value == -1) {
        return nullptr;
    }

    TreeNode* node = new TreeNode(value);
    cout << "Enter left child of " << value << endl;
    node->left = buildTree();
    cout << "Enter right child of " << value << endl;
    node->right = buildTree();

    return node;
}

int main() {
    TreeNode* root = buildTree();

    Solution sol;
    int result = sol.getMinimumDifference(root);

    cout << "Minimum Absolute Difference: " << result << endl;

    return 0;
}
