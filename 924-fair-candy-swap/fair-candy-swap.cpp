class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0;
        int sumB = 0;
        for (int x : aliceSizes)
            sumA += x;
        for (int x : bobSizes)
            sumB += x;
        int diff = (sumA - sumB)/2;
        unordered_map<int, bool> mp;
        for (int x : bobSizes)
            mp[x] = true;
        for (int a : aliceSizes){
            int b = a-diff;
            if (mp[b])
                return {a,b};
        }
        return {};
    }
};