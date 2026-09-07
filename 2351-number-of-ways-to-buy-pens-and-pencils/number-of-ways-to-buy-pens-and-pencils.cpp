class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans;
        for (int i = 0; i <= total / cost1; i++){
            int remaining = total - i*cost1;
            ans += remaining / cost2+1;
        }
        return ans;
    }
};