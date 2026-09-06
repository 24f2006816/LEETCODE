class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> freq(51,0);
        int ans = 0;
        for (int x : nums)
            freq[x]++;

        for (int x = 1; x <= 50; x++){
            if (freq[x] == 2)
                ans ^= x;
        }
        return ans;
    }
};