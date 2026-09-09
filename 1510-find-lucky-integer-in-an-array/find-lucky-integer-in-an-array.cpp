class Solution {
public:
    int findLucky(vector<int>& arr) {

        unordered_map<int, int> mp;

        // Frequency count
        for (int x : arr) {
            mp[x]++;
        }

        int ans = -1;

        // Find lucky integer
        for (auto it : mp) {

            int num = it.first;
            int freq = it.second;

            if (num == freq) {
                ans = max(ans, num);
            }
        }

        return ans;
    }
};