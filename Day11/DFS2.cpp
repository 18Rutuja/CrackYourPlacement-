class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)return 0;
     
        int left = minDepth(root -> left);
        int right = minDepth(root -> right);

      if(right !=0 && left==0){
        return 1+right;
      }else if(right ==0 && left != 0){
        return left+1;
      }else{
        return min(left , right) +1;
      }
    
    }
};