class Solution {
public:
    int countValidPrefixes(string s) {
        int zeroes = 0;
        int ones = 0;
        int count = 0;

        for (char c : s){
            if (c == '0')
                zeroes++;
            else
                ones++;
            if (abs(zeroes - ones) <= 1)
                count++;
        }
        return count;
    }
};