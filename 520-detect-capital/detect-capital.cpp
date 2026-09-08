class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital = 0;
        for (char ch : word){
            if (ch >= 'A' && ch <= 'Z')
                capital++;
        }
        if (capital == 0)
            return true;
        if (capital == word.size())
            return true;
        if (capital == 1 && word[0] >= 'A' && word[0] <= 'Z')
            return true;
        return false;
    }
};