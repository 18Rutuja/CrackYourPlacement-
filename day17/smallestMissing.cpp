#include <iostream>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        unordered_map<int,int> mp;
        int mx = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(arr[i] < 0) arr[i] = 0;
            mp[arr[i]]++;
            mx = max(mx, arr[i]);
        }
        int count = 1;
        while(count <= mx) {
            if(mp[count] == 0) return count;
            count++;
        }
        return count;
    } 
};

int main() {
    Solution sol;
    
    // Example 1
    int arr1[] = {3, 4, -1, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Smallest positive missing number in arr1: " << sol.missingNumber(arr1, n1) << endl;
    
    // Example 2
    int arr2[] = {1, 2, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Smallest positive missing number in arr2: " << sol.missingNumber(arr2, n2) << endl;
    
    // Example 3
    int arr3[] = {7, 8, 9, 11, 12};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Smallest positive missing number in arr3: " << sol.missingNumber(arr3, n3) << endl;

    return 0;
}
