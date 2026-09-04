class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ans;
        int n = words.size();

        for (int i = 0; i < n; ) {

            int j = i;
            int letters = 0;

            // Find all words that fit in this line
            while (j < n &&
                   letters + words[j].size() + (j - i) <= maxWidth) {

                letters += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            int spaces = maxWidth - letters;

            string line = "";

            // Last line OR only one word
            if (j == n || gaps == 0) {

                for (int k = i; k < j; k++) {

                    if (k > i)
                        line += " ";

                    line += words[k];
                }

                line += string(maxWidth - line.size(), ' ');
            }

            // Normal fully justified line
            else {

                int space = spaces / gaps;
                int extra = spaces % gaps;

                for (int k = i; k < j; k++) {

                    line += words[k];

                    if (k < j - 1) {

                        line += string(space, ' ');

                        if (extra > 0) {
                            line += ' ';
                            extra--;
                        }
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};