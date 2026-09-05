class WordFilter {
    unordered_map<string, int> mp;
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); i++){
            string w = words[i];
            for (int p = 0; p <= w.size(); p++)
                for (int s = 0; s <= w.size(); s++)
                    mp[w.substr(0,p) + "#" + w.substr(s)] = i;
        }
    }
    
    int f(string pref, string suff) {
        string key = pref + "#" + suff;
        return mp.count(key) ? mp[key] : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */