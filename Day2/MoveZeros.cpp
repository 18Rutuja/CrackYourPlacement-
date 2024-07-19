#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[right], nums[left]);
                left++;
            }
        }
    }
};

int main() {
    // Create a sample vector with some zeroes
    vector<int> nums = {0, 1, 0, 3, 12};

    // Create an instance of the Solution class
    Solution solution;
    solution.moveZeroes(nums);

    // Output the result
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
