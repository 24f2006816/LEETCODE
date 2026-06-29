class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        
        std::string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            // While prefix is not at the 0th index of strs[i]
            while (strs[i].find(prefix) != 0) {
                // Remove the last character from the prefix
                prefix = prefix.substr(0, prefix.length() - 1);
                
                if (prefix.empty()) {
                    return "";
                }
            }
        }
        
        return prefix;
    }
};