// #include <iostream>
// #include <vector>
// #include <algorithm> // for sort()
// #include <climits>   // for INT_MAX
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findMinDiff(vector<long long> a, long long n, long long m) {
        sort(a.begin(), a.end());
        
        long long mini = INT_MAX;
        int i = 0;
        int j = m - 1;
        while (j < n) {
            long long diff = a[j] - a[i];
            mini = min(mini, diff);
            i++;
            j++;
        }
        return mini;
    }
};

int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    Solution s;
    long long result = s.findMinDiff(a, n, m);
    cout << result << endl;

    return 0;
}
