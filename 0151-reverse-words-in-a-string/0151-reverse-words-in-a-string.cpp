class Solution {
public:
    string reverseWords(string s) {
        std::stringstream ss(s);
        std::string word, res;
        std::vector<std::string> words;

        while (ss >> word){
            words.push_back(word);
        }
        for (int i = words.size()-1; i >=0; --i){
            res += words[i];
            if (i > 0){
                res += " ";
            }
        }
        return res;
    }
};