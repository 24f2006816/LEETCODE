class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int cnt[101] = {};
        for (int x : nums){
            cnt[x]++;
            if (cnt[x] > 2)
                return false;
        }
        return true;
    }
};