
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long common = min(need1, need2);

        long long total = common * min(costBoth, cost1 + cost2);

        total += 1LL * (need1 - common) * min(cost1, costBoth);

        total += 1LL * (need2 - common) * min(cost2, costBoth);

        return total;
    }
};
