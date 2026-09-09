class Solution {
public:
    char findTheDifference(string s, string t) {

        unordered_map<char, int> mp;

        // s ke characters count karo
        for (char ch : s) {
            mp[ch]++;
        }

        // t ke characters check karo
        for (char ch : t) {
            mp[ch]--;

            if (mp[ch] < 0) {
                return ch;
            }
        }

        return ' ';
    }
};