class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] == 0){
                if (i+1 < arr.size() && arr[i+1] == 0)
                    return true;
            }
            else if (binary_search(arr.begin(), arr.end(), 2*arr[i])){
                return true;
            }
        }
        return false;
    }
};