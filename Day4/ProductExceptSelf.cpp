#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
   
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here  
        vector<long long int> ans(n , 1);
        
        long long int leftProd =  1;
        
        for(int i=0; i<n; i++){
           ans[i] = leftProd;
           leftProd *= nums[i];
        }
        
        long long int rightProd =  1;
        for(int i=n-1 ; i>=0; i--){
            ans[i] *= rightProd;
            rightProd *= nums[i];
        }
        
      return ans;  
    }
};

int main(){
    int n;
    cin>>n;
    vector<long long int> nums(n);
    for(int i=0; i<n; i++ ){
        cin>>nums[i];
    }

    Solution s;
    
    vector<long long int> ans2 = s.productExceptSelf(nums ,n);
    for(int i=0; i<n; i++ ){
        cout<<ans2[i]<<" ";
    }
    
 return 0;

}