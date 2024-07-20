#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        sort(strs.begin(), strs.end());
        int n = strs.size();
        string ans = "";

        for (int i = 0; i < strs[0].size(); i++) {
            if (strs[0][i] != strs[n-1][i]) {
                break;
            } else {
                ans += strs[0][i];
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> test1 = {"flower", "flow", "flight"};
    vector<string> test2 = {"dog", "racecar", "car"};
    vector<string> test3 = {"interspecies", "interstellar", "interstate"};
    vector<string> test4 = {"throne", "throne"};
    vector<string> test5 = {"apple", "ape", "april"};

    cout << "Test 1: " << solution.longestCommonPrefix(test1) << endl;
    cout << "Test 2: " << solution.longestCommonPrefix(test2) << endl;
    cout << "Test 3: " << solution.longestCommonPrefix(test3) << endl;
    cout << "Test 4: " << solution.longestCommonPrefix(test4) << endl;
    cout << "Test 5: " << solution.longestCommonPrefix(test5) << endl;

    return 0;
}

