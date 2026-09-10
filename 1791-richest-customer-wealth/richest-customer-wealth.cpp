class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int richest = 0;
        for (int i = 0; i < accounts.size(); i++){
            int wealth = 0;
            for (int j =0; j < accounts[i].size(); j++){
                wealth += accounts[i][j];
            }
            if (wealth > richest){
                richest = wealth;
            }
        }
        return richest;
    }
};