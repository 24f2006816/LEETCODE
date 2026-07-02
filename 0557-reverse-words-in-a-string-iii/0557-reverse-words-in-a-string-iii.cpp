class Solution {
public:
    string reverseWords(string s) {
        int  n = s.size();
        int i = 0;

        while ( i < n){
            while ( i < n && s[i] == ' ')
                i++;
            int j = i;
            while (j < n && s[j] != ' ')
                j++;
            reverse(s.begin()+i, s.begin()+j);
            i=j;
        }
        return s;
    }
};