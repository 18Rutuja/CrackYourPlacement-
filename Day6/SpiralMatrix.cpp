class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n= matrix.size();//colomn
        int m = matrix[0].size();//row
        int left =0, right = m-1;//row
        int top = 0, bottom = n-1;//colomn
        vector<int>ans;
        
        while(left<=right && top<=bottom){
            // left++;
            for(int i=left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            
            top++;
            for(int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            
            right--;
            if(top<=bottom){
                for(int i=right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            
        }
        return ans;
    }
};