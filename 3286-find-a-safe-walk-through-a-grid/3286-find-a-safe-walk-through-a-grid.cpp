class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));

        int start = health - grid[0][0];
        if (start <= 0) return false;

        priority_queue<vector<int>> pq;
        pq.push({start, 0, 0});
        best[0][0] = start;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int h = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (r == m - 1 && c == n - 1)
                return true;

            if (h < best[r][c]) continue;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int nh = h - grid[nr][nc];

                if (nh > 0 && nh > best[nr][nc]) {
                    best[nr][nc] = nh;
                    pq.push({nh, nr, nc});
                }
            }
        }

        return false;
    }
};