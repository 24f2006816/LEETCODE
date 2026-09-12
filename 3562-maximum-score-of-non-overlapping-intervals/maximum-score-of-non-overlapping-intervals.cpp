class Solution {
public:

    struct Interval {
        int start;
        int end;
        int weight;
        int index;
    };

    struct State {
        long long score;
        vector<int> indices;
        bool calculated;

        State() {
            score = 0;
            calculated = false;
        }
    };

    vector<vector<State>> dp;

    // ---------------- MERGE SORT ----------------

    void merge(vector<Interval>& a, int l, int m, int r) {

        vector<Interval> temp;

        int i = l;
        int j = m + 1;

        while (i <= m && j <= r) {

            if (a[i].start < a[j].start ||
                (a[i].start == a[j].start &&
                 a[i].index < a[j].index)) {

                temp.push_back(a[i]);
                i++;
            }
            else {
                temp.push_back(a[j]);
                j++;
            }
        }

        while (i <= m) {
            temp.push_back(a[i]);
            i++;
        }

        while (j <= r) {
            temp.push_back(a[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            a[l + k] = temp[k];
        }
    }

    void mergeSort(vector<Interval>& a, int l, int r) {

        if (l >= r)
            return;

        int m = l + (r - l) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }

    // ---------------- BINARY SEARCH ----------------

    int findNext(vector<Interval>& a, int end) {

        int l = 0;
        int r = a.size();

        while (l < r) {

            int mid = l + (r - l) / 2;

            if (a[mid].start > end)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }

    // ---------------- LEXICOGRAPHIC COMPARISON ----------------

    bool lexicographicallySmaller(
        vector<int>& a,
        vector<int>& b
    ) {

        int n = a.size();
        int m = b.size();

        int len = n < m ? n : m;

        for (int i = 0; i < len; i++) {

            if (a[i] < b[i])
                return true;

            if (a[i] > b[i])
                return false;
        }

        // If one is prefix of the other,
        // shorter one is lexicographically smaller.
        return n < m;
    }

    // ---------------- SORT INDICES ----------------

    void sortIndices(vector<int>& v) {

        for (int i = 0; i < v.size(); i++) {

            for (int j = i + 1; j < v.size(); j++) {

                if (v[j] < v[i]) {

                    int temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
        }
    }

    // ---------------- DP ----------------

    State solve(
        int i,
        int k,
        vector<Interval>& a,
        vector<int>& next
    ) {

        if (i == a.size() || k == 0) {

            State base;
            base.calculated = true;

            return base;
        }

        if (dp[i][k].calculated)
            return dp[i][k];

        // ----------------
        // SKIP
        // ----------------

        State skip = solve(
            i + 1,
            k,
            a,
            next
        );

        // ----------------
        // TAKE
        // ----------------

        State take = solve(
            next[i],
            k - 1,
            a,
            next
        );

        take.score += a[i].weight;

        take.indices.push_back(a[i].index);

        sortIndices(take.indices);

        // ----------------
        // CHOOSE
        // ----------------

        State result;

        if (take.score > skip.score) {

            result = take;

        }
        else if (take.score < skip.score) {

            result = skip;

        }
        else {

            // SAME SCORE
            //
            // ONLY lexicographical order matters.

            if (lexicographicallySmaller(
                    take.indices,
                    skip.indices)) {

                result = take;
            }
            else {

                result = skip;
            }
        }

        result.calculated = true;

        dp[i][k] = result;

        return result;
    }

    // ---------------- MAIN ----------------

    vector<int> maximumWeight(
        vector<vector<int>>& intervals
    ) {

        int n = intervals.size();

        vector<Interval> a(n);

        for (int i = 0; i < n; i++) {

            a[i].start = intervals[i][0];
            a[i].end = intervals[i][1];
            a[i].weight = intervals[i][2];
            a[i].index = i;
        }

        // Sort by starting time
        mergeSort(a, 0, n - 1);

        // Find next non-overlapping interval
        vector<int> next(n);

        for (int i = 0; i < n; i++) {

            next[i] = findNext(
                a,
                a[i].end
            );
        }

        // At most 4 intervals
        dp.assign(
            n + 1,
            vector<State>(5)
        );

        State answer = solve(
            0,
            4,
            a,
            next
        );

        return answer.indices;
    }
};