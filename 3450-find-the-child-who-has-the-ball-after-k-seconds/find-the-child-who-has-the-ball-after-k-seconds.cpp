class Solution {
public:
    int numberOfChild(int n, int k) {
        int pos = 0;
        int direction = 1;
        while (k--){
            pos += direction;
            if (pos == n-1){
                direction = -1;
            }
            else if (pos == 0){
                direction =1;
            }
        }     
        return pos;
    }
};