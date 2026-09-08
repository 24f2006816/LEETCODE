class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rows;

        for (int i = 0; i < mat.size(); i++) {
            int l = 0, r = mat[i].size();

            // First 0 find karo
            while (l < r) {
                int mid = l + (r - l) / 2;

                if (mat[i][mid] == 1)
                    l = mid + 1;
                else
                    r = mid;
            }

            rows.push_back({l, i});
        }

        // Manual sorting by strength, then index
        for (int i = 0; i < rows.size(); i++) {
            for (int j = i + 1; j < rows.size(); j++) {
                if (rows[j].first < rows[i].first ||
                   (rows[j].first == rows[i].first &&
                    rows[j].second < rows[i].second)) {
                    swap(rows[i], rows[j]);
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < k; i++)
            ans.push_back(rows[i].second);

        return ans;
    }
};