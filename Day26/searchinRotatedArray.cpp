#include<bits/stdc++.h>
using namespace std;


int find(vector<int> &v , int k){
    int n = v.size();
    int mid;
    int low =0;
    int high = n-1;


    while(low <= high){
         mid = low + (high-low)/2;
         if(v[mid] == k)return mid;

         if(v[low] == v[mid] && v[mid] == v[high]){
            low = low +1;
            high = high -1;
            continue;
         }
         if(v[low] <= v[mid]){
            if(v[low] <= k && k<= v[mid]){
                high  = mid-1;
            }else{
                low = mid +1;
            }
         }else{
             if(v[low] <= k && k<= v[mid]){
                low = mid +1;
            }else{
                high = mid-1;
            }
         }
         return -1;
    }


}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);

    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }

    cout<<"Enter target"<<endl;
    int k;
    cin>>k;
    int res = find(v , k);

     if(res != -1)
        cout << "Element found at index: " << res << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}