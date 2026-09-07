class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;

        for (int d = 0; d < m + n - 1; d++) {
            int r = max(0, d - n + 1);
            int c = d - r;

            vector<int> temp;

            while (r < m && c >= 0) {
                temp.push_back(mat[r][c]);
                r++;
                c--;
            }

            if (d % 2 == 0)
                reverse(temp.begin(), temp.end());

            for (int x : temp)
                ans.push_back(x);
        }

        return ans;
    }
};