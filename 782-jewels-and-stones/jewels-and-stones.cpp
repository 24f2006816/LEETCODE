class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<int,bool> mp;
        for(char ch : jewels) {
            mp[ch] = true;
        }
        int count = 0;
        for(char ch : stones) {
            if(mp[ch]) count++;
        }
        return count;
    }
};