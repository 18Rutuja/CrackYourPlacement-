#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while (n > 0) {
            n--;
            int currentdigit = n % 26;
            n = n / 26;
            ans.push_back(currentdigit + 'A');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    Solution s;
    string result = s.convertToTitle(n);
    cout << "The Excel column title is: " << result << endl;

    return 0;
}
