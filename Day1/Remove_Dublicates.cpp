
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    set<int>st;
    for (int i = 0; i < n; i++) {
        st.insert(v[i]);
    }

    for (auto it = st.begin(); it != st.end(); ++it) {
        cout << *it << " ";
    }
    
    return 0;
}

