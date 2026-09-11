class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (char ch : s){
            mp[ch]++;
        }
        int ans = 0;
        bool odd = false;
        for (auto it : mp){
            int freq = it.second;
            ans += (freq/2)*2;
            if (freq % 2 == 1){
                odd = true;
            } 
        }
        if (odd)
            ans++;
        return ans;
    }
};