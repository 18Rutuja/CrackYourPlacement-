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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < size; ++i) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp != nullptr) {
                    currentLevel.push_back(temp->val);

                    if (temp->left) {
                        q.push(temp->left);
                    }
                    if (temp->right) {
                        q.push(temp->right);
                    }
                }
            }

            result.push_back(currentLevel);
        }

        return result;
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
    vector<vector<int>> result = sol.levelOrder(root);

    cout << "Level Order Traversal:" << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
