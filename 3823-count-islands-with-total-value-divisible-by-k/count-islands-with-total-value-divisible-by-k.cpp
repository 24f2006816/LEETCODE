class Solution {
public:
    long long dfs(int i, int j, vector<vector<int>>& grid,
                  vector<vector<bool>>& visited, int k) {
        int m = grid.size();
        int n = grid[0].size();

        visited[i][j] = true;

        long long sum = grid[i][j];

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int x = i + dx[d];
            int y = j + dy[d];

            if (x >= 0 && x < m &&
                y >= 0 && y < n &&
                !visited[x][y] && grid[x][y] != 0) {
                sum += dfs(x, y, grid, visited, k);
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && !visited[i][j]) {
                    long long sum = dfs(i, j, grid, visited, k);

                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};