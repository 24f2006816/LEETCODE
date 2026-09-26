class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        // Store key -> value
        for (auto &p : knowledge) {
            mp[p[0]] = p[1];
        }

        string ans;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] != '(') {
                ans += s[i];
            }
            else {
                // Find closing bracket
                int j = i + 1;

                while (s[j] != ')') {
                    j++;
                }

                // Extract key
                string key = s.substr(i + 1, j - i - 1);

                // Replace with value if present
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                }
                else {
                    ans += '?';
                }

                // Jump past ')'
                i = j;
            }
        }

        return ans;
    }
};