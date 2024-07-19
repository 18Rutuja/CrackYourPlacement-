#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0) return 0; // If needle is an empty string, return 0
        
        for (int i = 0; i <= n - m; i++) {
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }
        return -1;
    }
};

int main() {

    string s1, s2;
    cin>>s1>>s2;

    Solution solution;

    int result = solution.strStr(s1, s2);
    cout << "The first occurrence of \"" << s1 << "\" in \"" << s2 << "\" is at index: " << result << endl;

    return 0;
}
