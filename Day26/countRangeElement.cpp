class Solution{
public:

    void inorder(Node* root , vector<int>&ans){
        
        if(root == NULL)return;
        
        inorder(root -> left, ans);
        ans.push_back(root -> data );
        inorder(root -> right, ans);
        
    }
    int getCount(Node *root, int l, int h)
    {
      // your code goes here   
      if(root == NULL) return 0;
      int cnt=0;
      vector<int> temp;
      inorder(root , temp);
      
      for(int i=0; i<temp.size(); i++){
          if(temp[i] >= l && temp[i] <= h){
              cnt++;
          }
      }
      return cnt;
     
    }
};