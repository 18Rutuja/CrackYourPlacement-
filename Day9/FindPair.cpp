#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPair(int n, int x, vector<int> &arr) {
        // Sort the array to enable the two-pointer approach
        sort(arr.begin(), arr.end());
        
        // Use two-pointer technique
        int i = 0;
        int j = 1;
        
        while (j < n) {
            int diff = arr[j] - arr[i];
            
            if (diff == x) {
                return 1; // Pair found with the required difference
            } else if (diff < x) {
                j++; // Increase the difference by moving the second pointer
            } else {
                i++; // Decrease the difference by moving the first pointer
                if (i == j) {
                    j++; // Ensure j is always ahead of i
                }
            }
        }
        
        return -1; // No pair found with the required difference
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int x;
    cin >> x;

    Solution s;
    int res = s.findPair(n, x, v);

    if (res == 1) {
        cout << "Pair with difference " << x << " found." << endl;
    } else {
        cout << "No pair with difference " << x << " found." << endl;
    }

    return 0;
}
