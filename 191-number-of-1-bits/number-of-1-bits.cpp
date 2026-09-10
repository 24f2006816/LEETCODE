class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        while (n > 0){
            int bit = n%2;
            if (bit == 1)
                res++;
            n = n/2;
        }
        return res;
    }
};