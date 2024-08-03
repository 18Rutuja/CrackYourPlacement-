#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <cmath> // For std::abs

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        
        sort(nums.begin(), nums.end());
        int mid = nums[nums.size()/2];
        int ans = 0;
        for(auto val : nums)
            ans += abs(mid - val);
        return ans;
    }
};

int main() {
    // Sample input
    vector<int> nums = {1, 2, 3};

    // Create a Solution object
    Solution solution;

    // Find the minimum number of moves
    int result = solution.minMoves2(nums);

    // Print the result
    cout << "Minimum number of moves: " << result << endl;

    return 0;
}
