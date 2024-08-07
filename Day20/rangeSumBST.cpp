
class Solution {
public:
    void inorder(TreeNode* root , vector<int>&temp){
        if(root == NULL)return;

        inorder(root -> left, temp);
        temp.push_back(root -> val);
        inorder(root -> right , temp);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> temp;
        inorder(root , temp);
int sum =0;
   for(int i=0; i<temp.size(); i++){
    if(temp[i] >= low && temp[i] <=high){
        sum+=temp[i];
    }
   }
   return sum;
    }
};


////////////////////////////////////

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
          if(!root) return 0;
        if(root->val >=low && root ->val <= high){
            return root ->val +rangeSumBST(root->left ,low,high)+rangeSumBST(root->right,low,high);
        }else if(root->val<low){
            return rangeSumBST(root->right,low,high);
        }else{
            return  rangeSumBST(root->left,low,high);
        }
    }
};