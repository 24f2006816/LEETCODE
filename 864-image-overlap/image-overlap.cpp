class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();

        vector<pair<int, int>> a;
        vector<pair<int, int>> b;

        // Store positions of 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (img1[i][j] == 1)
                    a.push_back({i, j});

                if (img2[i][j] == 1)
                    b.push_back({i, j});
            }
        }

        map<pair<int, int>, int> freq;

        int ans = 0;

        for (auto p : a) {
            for (auto q : b) {

                int dr = q.first - p.first;
                int dc = q.second - p.second;

                freq[{dr, dc}]++;

                if (freq[{dr, dc}] > ans)
                    ans = freq[{dr, dc}];
            }
        }

        return ans;
    }
};