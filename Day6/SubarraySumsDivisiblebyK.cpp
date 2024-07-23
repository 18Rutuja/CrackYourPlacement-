class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        int count = 0;
        unordered_map<int, int> remainderFreq;
        remainderFreq[0] = 1; // Initialize with one zero remainder
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % k; // Calculate current prefix sum modulo k
            if (sum < 0) sum += k; // Make sure sum is positive

            count += remainderFreq[sum]; // Add the number of subarrays with the same remainder
            remainderFreq[sum]++; // Update frequency of remainder
        }

        return count;
    }
};
