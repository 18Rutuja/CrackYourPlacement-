class Solution {
public:
   int sumOfLeftLeaves(TreeNode* root) {
    if (root == NULL) {
        return 0; // Base case: if the node is null, the sum of left leaves is zero
    }

    int sum = 0; // Variable to hold the sum of left leaves

    // Check if there's a left child and it's a leaf
    if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
        sum += root->left->val; // Add the value of the left leaf to the sum
    }

    // Recursively calculate the sum of left leaves for the left and right subtrees
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}
};