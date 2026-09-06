class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = 0, j =-1;
        for (int i =0; i < forts.size(); i++){
            if (forts[i]){
                if (j != -1 && forts[i] != forts[j])
                    ans =max(ans, i-j-1);
                    j = i;
            }
        }
        return ans;
    }
};