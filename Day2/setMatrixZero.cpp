#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Helper functions to mark rows and columns
        auto markRow = [](vector<vector<int>>& matrix, int m, int i) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] != 0) {
                    matrix[i][j] = -1;
                }
            }
        };

        auto markCol = [](vector<vector<int>>& matrix, int n, int j) {
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] != 0) {
                    matrix[i][j] = -1;
                }
            }
        };

        // First pass: mark the rows and columns
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    markRow(matrix, m, i);
                    markCol(matrix, n, j);
                }
            }
        }

        // Second pass: update the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    Solution solution;
    solution.setZeroes(matrix);

    // Output the matrix
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
