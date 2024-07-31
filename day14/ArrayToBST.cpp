
class Solution {
public:
    TreeNode* solve(vector<int>&nums, int left, int right){
       if(left > right){
            return NULL;
        }

        int mid = left + (right - left)/2;
        TreeNode * node = new TreeNode(nums[mid]);
        node -> left = solve(nums , left , mid-1);
        node -> right = solve(nums , mid+1, right);

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0 , nums.size()-1);
    }
};