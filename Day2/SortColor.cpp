#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int  n = nums.size();

        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){
                if(nums[j] > nums[j+1]){
                    swap(nums[j] , nums[j+1]);
                }
            }
        }
        for(int i=0; i<n; i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    Solution s;
    s.sortColors(v);
    for(int i=0; i<n; i++){
      cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}