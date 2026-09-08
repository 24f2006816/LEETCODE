class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {

            int vowels = 0;
            int consonants = 0;

            for(int j = i; j < n; j++) {

                if(isVowel(s[j]))
                    vowels++;
                else
                    consonants++;

                if(vowels == consonants &&
                   (vowels * consonants) % k == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};