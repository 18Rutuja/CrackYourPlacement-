#include<bits/stdc++.h>
using namespace std;

int moorsVotingAlgo(vector<int> &v){
    int n = v.size();
    int el;
    int cnt =0;

    for(int i=0; i<n; i++){
        if(cnt ==0){
            cnt =1;
            el = v[i];
        }
        else if(el == v[i])cnt++;
        else cnt--;
    }
  int cnt1 =0;
  for(int i=0; i<n; i++){
    if(v[i] == el)cnt1++;
  }
  if(cnt1 > n/2)return el;
  return -1;
}

int findMejority(vector<int> &v){
    unordered_map<int , int>mpp;
    int n =v.size();
    int res=-1; 
    for(int i=0; i<v.size(); i++){
        mpp[v[i]]++;
    }
    for( auto i: mpp){
        if(i.second  > n/2){
            res = i.first;
        }
    }
    return res;
    }

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int result = findMejority(v);
    int res2 = moorsVotingAlgo(v);
    cout<<"ans by using moors algo"<<res2<<endl; 
    if(result != -1){
         cout<<result<<endl;
    }else{
        cout<<"element not present"<<endl;
    }
    return 0;
}