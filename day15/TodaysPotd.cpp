class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        vector<int> ans;
        int n = matrix.size();//row
        int m = matrix[0].size();//col
        
        int right =m-1;
        int left = 0;
        int top = 0;
        int bottom = n-1;
        
        while(left<=right && top<=bottom){
            //left to right
         for(int i=left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            //top to bottom
            for(int i=top; i<= bottom; i++ ){
                ans.push_back(matrix[i][right]);
            }
            right--;
            
            //right to left
            if(top <= bottom){
                for(int i=right; i>= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            //bottom to top
            if(left <= right){
                for(int i=bottom; i>= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
        
    }
};