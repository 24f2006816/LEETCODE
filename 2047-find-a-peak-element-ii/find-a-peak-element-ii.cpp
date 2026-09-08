class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                int current = mat[i][j];

                int up = -1;
                int down = -1;
                int left = -1;
                int right = -1;

                // Up
                if (i > 0)
                    up = mat[i - 1][j];

                // Down
                if (i < rows - 1)
                    down = mat[i + 1][j];

                // Left
                if (j > 0)
                    left = mat[i][j - 1];

                // Right
                if (j < cols - 1)
                    right = mat[i][j + 1];

                // Check peak
                if (current > up &&
                    current > down &&
                    current > left &&
                    current > right) {

                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }
};