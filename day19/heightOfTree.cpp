#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int ans = max(left, right) + 1;
        return ans;
    }
};

TreeNode* build(TreeNode* root) {
    cout << "Enter node data (-1 for NULL): ";
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    root = new TreeNode(data);

    cout << "Enter left child of " << data << endl;
    root->left = build(root->left);

    cout << "Enter right child of " << data << endl;
    root->right = build(root->right);

    return root;
}

int main() {
    TreeNode* root = NULL;
    root = build(root);

    Solution sol;
    int ans = sol.maxDepth(root);
    cout << "Max Depth of the Tree: " << ans << endl;

    return 0;
}
