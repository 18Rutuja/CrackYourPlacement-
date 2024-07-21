#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string str = ""; 
        int n = s.length();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                reverse(str.begin(), str.end());
                ans += str;
                ans += ' ';
                str = "";
            } else {
                str += s[i];
            }
        }
        reverse(str.begin(), str.end());
        ans += str;
        
        // Remove trailing space if any
        if (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        
        return ans;
    }
};

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    Solution sol;
    string result = sol.reverseWords(s);
    cout << "Reversed words in string: " << result << endl;

    return 0;
}
