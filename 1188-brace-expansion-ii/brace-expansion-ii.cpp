class Solution {
public:
    string s;
    int i;

    set<string> parseExpression() {
        set<string> res = parseTerm();

        while (i < s.size() && s[i] == ',') {
            i++;

            set<string> nxt = parseTerm();

            res.insert(nxt.begin(), nxt.end());
        }

        return res;
    }

    set<string> parseTerm() {
        set<string> res = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur = parseFactor();

            set<string> temp;

            for (string a : res) {
                for (string b : cur) {
                    temp.insert(a + b);
                }
            }

            res = temp;
        }

        return res;
    }

    set<string> parseFactor() {
        if (s[i] != '{') {
            string x(1, s[i]);
            i++;
            return {x};
        }

        i++; // {

        set<string> res = parseExpression();

        i++; // }

        return res;
    }

    vector<string> braceExpansionII(string expr) {
        s = expr;
        i = 0;

        set<string> ans = parseExpression();

        return vector<string>(ans.begin(), ans.end());
    }
};