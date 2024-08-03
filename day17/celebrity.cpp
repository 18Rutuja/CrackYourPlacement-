#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int res = -1;
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count1 += mat[i][j];
                count2 += mat[j][i];
            }
            if (count1 == 0 && count2 == n - 1) {
                res = i;
            }
            count1 = 0;
            count2 = 0;
        }
        return res;
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Enter the number of people in the party: ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter the " << n << "x" << n << " matrix (0 or 1):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    int result = solution.celebrity(mat);
    if (result != -1) {
        cout << "Celebrity is at index: " << result << endl;
    } else {
        cout << "There is no celebrity in the party." << endl;
    }

    return 0;
}
