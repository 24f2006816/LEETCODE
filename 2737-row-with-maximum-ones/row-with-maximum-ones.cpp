class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxOnes = 0, maxRow = 0;
        for (int i = 0; i < mat.size(); i++){
            int count = 0;
            for (int j = 0; j < mat[i].size(); j++){
                if (mat[i][j] == 1){
                    count ++;
                }
            }
            if (count > maxOnes){
                maxOnes = count;
                maxRow = i;
            }
        }
        return {maxRow, maxOnes};
    }
};