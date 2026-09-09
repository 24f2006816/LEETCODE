class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char, int> mp;

        // Count frequency
        for (char ch : s) {
            mp[ch]++;
        }

        // Find first unique
        for (int i = 0; i < s.length(); i++) {
            if (mp[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};