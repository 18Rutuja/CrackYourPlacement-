#include <iostream>
#include <vector>
using namespace std;

// Assuming the Solution class is defined as below
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m + n);
        int i = 0; // Pointer for nums1
        int j = 0; // Pointer for nums2
        int k = 0; // Pointer for temp

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                temp[k] = nums1[i];
                i++;
            } else {
                temp[k] = nums2[j];
                j++;
            }
            k++;
        }

        // Copy any remaining elements from nums1, if any
        while (i < m) {
            temp[k] = nums1[i];
            i++;
            k++;
        }

        // Copy any remaining elements from nums2, if any
        while (j < n) {
            temp[k] = nums2[j];
            j++;
            k++;
        }

        // Copy the merged result back to nums1
        for (int idx = 0; idx < m + n; idx++) {
            nums1[idx] = temp[idx];
        }
    }
};

int main() {
    Solution sol;
    
    // Example test case
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3; // Number of initialized elements in nums1
    vector<int> nums2 = {2, 5, 6};
    int n = 3; // Number of elements in nums2

    // Call the merge function
    sol.merge(nums1, m, nums2, n);

    // Print the result
    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
