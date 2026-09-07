class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0)
            return {};

        sort(changed.begin(), changed.end());

        unordered_map<int, int> freq;

        for (int x : changed)
            freq[x]++;

        vector<int> ans;

        for (int x : changed) {

            if (freq[x] == 0)
                continue;

            if (freq[2 * x] == 0)
                return {};

            ans.push_back(x);

            freq[x]--;
            freq[2 * x]--;
        }

        return ans;
    }
};