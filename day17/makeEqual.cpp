#include <iostream>
#include <vector>
#include <algorithm> // For std::is_permutation

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // Check if the two vectors are permutations of each other
        return is_permutation(target.begin(), target.end(), arr.begin());
    }
};

int main() {
    // Sample input
    vector<int> target = {1, 2, 3, 4};
    vector<int> arr = {2, 4, 1, 3};

    // Create a Solution object
    Solution solution;

    // Check if the arrays can be made equal by rearranging
    bool result = solution.canBeEqual(target, arr);

    // Print the result
    if(result) {
        cout << "The arrays can be made equal by rearranging their elements." << endl;
    } else {
        cout << "The arrays cannot be made equal by rearranging their elements." << endl;
    }

    return 0;
}
