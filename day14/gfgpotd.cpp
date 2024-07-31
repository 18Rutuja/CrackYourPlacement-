#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int n = arr.size();
        string ans ="";
        sort(arr.begin(), arr.end());
        
        string s1 = arr[0];
        string s2 = arr[n-1];
        

        
        for(int i=0; i< min(s1.size() , s2.size()); i++){
            if(s1[i] == s2[i]){
                ans += s1[i];
            
            }else{
                break;
            }
        }
        if(ans == ""){
            return "-1";
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<string>str(n);

    for(int i=0; i<n; i++){
     
      cin>>str[i];
    }

    Solution s;
    string res = s.longestCommonPrefix(str);
    if(res != "-1"){
        cout<<res<<endl;
    }else{
        cout<<"-1"<<endl;
    }
    return 0;
}