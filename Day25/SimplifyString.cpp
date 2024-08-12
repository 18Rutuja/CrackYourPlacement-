class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string item;
        
        while (getline(ss, item, '/')) {
            if (item == ".." && !stack.empty()) {
                stack.pop_back();
            } else if (!item.empty() && item != "." && item != "..") {
                stack.push_back(item);
            }
        }
        
        string result;
        for (const string& dir : stack) {
            result += "/" + dir;
        }
        
        return result.empty() ? "/" : result;
    }
};