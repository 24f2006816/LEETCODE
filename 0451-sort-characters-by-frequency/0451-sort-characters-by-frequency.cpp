class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;


        sort(s.begin(), s.end(), [&](char a , char b){
            if (mp[a] == mp[b])
                return a < b;
            return mp[a] > mp[b];
        });
        return s;
    }
};