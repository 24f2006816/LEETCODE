class Solution {
public:
    int minSteps(string s, string t) {
        int freq[26] = {0};

        for(char ch : s)
            freq[ch - 'a']++;

        for(char ch : t)
            freq[ch - 'a']--;

        int ans = 0;

        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0)
                ans += freq[i];
        }

        return ans;
    }
};