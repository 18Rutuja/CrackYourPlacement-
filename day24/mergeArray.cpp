#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v1, vector<int>&v2){
   
   int n= v1.size();
   int m = v2.size();
   int i= n-1;
   int j= 0;

   while(i>=0 && j<m){
    if(v1[i]>v2[j]){
        swap(v1[i] , v2[j]);
        i--;
        j++;
    }else if(v1[i]<=v2[j]){
       i--;
       j++;
    }
   }

   sort(v1.begin(), v1.end());
   sort(v2.begin(), v2.end());


}

int main(){

int n=5;
int m= 4;
    vector<int>v1 = {1 ,4 , 8 ,10, 11};
    vector<int>v2 = {3 , 6 , 7,8};

    merge(v1, v2);

    for(int i=0; i<n; i++){
cout<<v1[i]<<" ";
    }
for(int j=0; j<m; j++){
    cout<<v2[j]<<" ";
}
return 0;
}

    

