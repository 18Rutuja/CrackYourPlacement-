#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        sort(a, a + n);
        sort(b, b + n, greater<long long>());
        
        for (int i = 0; i < n; i++) {
            if ((a[i] + b[i]) < k) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the arrays: ";
    cin >> n;
    
    long long *a = new long long[n];
    long long *b = new long long[n];
    
    cout << "Enter the elements of array a: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << "Enter the elements of array b: ";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    long long k;
    cout << "Enter the value of k: ";
    cin >> k;
    
    Solution sol;
    bool result = sol.isPossible(a, b, n, k);
    
    if (result) {
        cout << "Possible" << endl;
    } else {
        cout << "Not Possible" << endl;
    }
    
    delete[] a;
    delete[] b;
    
    return 0;
}
