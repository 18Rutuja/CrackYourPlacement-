
#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> findDuplicateApproachTwo(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int, int> mpp;

        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(auto i: mpp){
            if(i.second >1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int num = abs(nums[i]);
            int index = num - 1;
            if (nums[index] < 0) {
                result.push_back(num);
            }
            nums[index] *= -1;
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    Solution s;
    vector<int> duplicates = s.findDuplicates(v);
    
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
