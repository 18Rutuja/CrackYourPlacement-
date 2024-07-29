class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        if (n == 0) return -1;
        int m = arr[0].size();
        
        int max_row_index = -1;
        int j = m - 1;  // Start from the top-right corner

        for (int i = 0; i < n; i++) {
            while (j >= 0 && arr[i][j] == 1) {
                j--;  // Move left if you encounter a 1
                max_row_index = i;  // Update the row index
            }
        }

        return max_row_index;
    }
};
