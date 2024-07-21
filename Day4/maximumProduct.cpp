#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int m1 = nums[n-1] * nums[n-2] * nums[n-3];
        int m2 = nums[0] * nums[1] * nums[n-1];
        return max(m1, m2);
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution s;
    int result = s.maximumProduct(nums);
    cout << "Maximum product of three numbers is: " << result << endl;

    return 0;
}
