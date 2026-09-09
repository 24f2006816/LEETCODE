class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        unordered_map<char, int> mp;

        // Jewels ko hashmap mein store karo
        for (char ch : jewels) {
            mp[ch] = 1;
        }

        int ans = 0;

        // Stones check karo
        for (char ch : stones) {
            if (mp[ch] == 1) {
                ans++;
            }
        }

        return ans;
    }
};