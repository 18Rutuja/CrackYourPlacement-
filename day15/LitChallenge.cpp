#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt =0;
        for(int i=0; i<details.size(); i++){
            string str = details[i].substr(11, 2);
            
            if(stoi(str) > 60){
                cnt++;
            }
            
        }
        return cnt;
    }
};

int main(){
     int n;
      cin>>n;

      vector<string> s(n);
      for(int i=0; i<n;i++){
        cin>>s[i];
      }
     
       
       Solution sol;
       int res = sol.countSeniors(s);
       return res;

}