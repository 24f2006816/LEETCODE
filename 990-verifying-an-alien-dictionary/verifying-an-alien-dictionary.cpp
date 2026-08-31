class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> orderMap;
        for (int i = 0; i <order.size(); i++){
            orderMap[order[i]] = i;
        }
        for (int i = 0; i < words.size()-1; i++){
            for (int j=0; j < words[i].length(); j++){
                if (j >= words[i+1].length()){
                    return false;
                }
                if (words[i][j] != words[i+1][j]){
                    int currentLetter = orderMap[words[i][j]];
                    int nextLetter = orderMap[words[i+1][j]];
                    if (nextLetter < currentLetter){
                        return false;
                    }
                    else{
                        break;
                    }
                }
            }
            
        }
        return true;
    }
};