class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<bool> vis;
    int ans = INT_MAX;

    void dfs(int node) {
        vis[node] = true;

        for (auto &it : adj[node]) {
            int next = it.first;
            int wt = it.second;

            ans = min(ans, wt);

            if (!vis[next])
                dfs(next);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        adj.resize(n + 1);
        vis.resize(n + 1, false);

        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        dfs(1);

        return ans;
    }
};