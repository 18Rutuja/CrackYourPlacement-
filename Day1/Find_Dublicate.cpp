
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int n) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
    }
    for (auto it : mpp) {
        if (it.second > 1) {
            return it.first;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << solve(v, n);
    return 0;
}
