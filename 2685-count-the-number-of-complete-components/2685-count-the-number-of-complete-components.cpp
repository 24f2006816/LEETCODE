class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited,
             int &nodes, int &degreeSum) {

        visited[node] = true;
        nodes++;
        degreeSum += adj[node].size();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, nodes, degreeSum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<int> adj[n];

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {

                int nodes = 0;
                int degreeSum = 0;

                dfs(i, adj, visited, nodes, degreeSum);

                int edgeCount = degreeSum / 2;

                if (edgeCount == nodes * (nodes - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};