#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> uniquePerms(vector<int> &arr, int n) {
        vector<vector<int>> st;
        
        sort(arr.begin(), arr.end());  // Sort the array to handle duplicates
        
        do {
            st.push_back(arr);  // Add the current permutation to the result
        } while (next_permutation(arr.begin(), arr.end()));  // Generate the next permutation
        
        return st;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution s;
    vector<vector<int>> result = s.uniquePerms(arr, n);

    // Print the result
    cout<< "result he re baba"<<endl;
    for (const auto &perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
