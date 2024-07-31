class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root != NULL) {
            findPaths(root, "", ans);
        }
        return ans;
    }

private:
    void findPaths(TreeNode* node, string path, vector<string>& ans) {
        if (node != NULL) {
            path += to_string(node->val);
            if (node->left == NULL && node->right == NULL) {  // if it's a leaf
                ans.push_back(path);  // add path to answer
            } else {
                path += "->";  // extend path
                findPaths(node->left, path, ans);
                findPaths(node->right, path, ans);
            }
        }
    }
};
