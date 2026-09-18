class Solution {
public:

    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        vector<int> first(26, -1);
        vector<int> last(26, -1);

        // Find first and last occurrence
        for (int i = 0; i < n; i++) {

            int x = s[i] - 'a';

            if (first[x] == -1)
                first[x] = i;

            last[x] = i;
        }

        vector<pair<int,int>> intervals;

        // Generate valid intervals
        for (int c = 0; c < 26; c++) {

            if (first[c] == -1)
                continue;

            int L = first[c];
            int R = last[c];

            bool valid = true;

            for (int i = L; i <= R; i++) {

                int x = s[i] - 'a';

                // This character occurs before L
                if (first[x] < L) {
                    valid = false;
                    break;
                }

                // Expand interval
                R = max(R, last[x]);
            }

            if (valid)
                intervals.push_back({L, R});
        }

        // Earliest finishing interval first
        sort(intervals.begin(), intervals.end(),
             [](pair<int,int>& a, pair<int,int>& b) {
                 return a.second < b.second;
             });

        vector<string> ans;

        int previousEnd = -1;

        for (auto &interval : intervals) {

            int L = interval.first;
            int R = interval.second;

            if (L > previousEnd) {

                ans.push_back(s.substr(L, R - L + 1));

                previousEnd = R;
            }
        }

        return ans;
    }
};