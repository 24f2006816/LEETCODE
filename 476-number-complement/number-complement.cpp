class Solution {
public:
    int findComplement(int num) {
        int mask = 0;
        int temp = num;
        while (temp > 0){
            mask = mask*2 + 1;
            temp /= 2;
        }
        return num ^ mask;
    }
};