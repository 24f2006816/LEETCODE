class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int current_floor = 0;
        int time_required = 0;
        for (int i = 0; i < requests.size(); i++){
            int seconds = abs(requests[i] - current_floor);
            
            time_required += seconds;
            current_floor = requests[i];
        }
        return time_required;
    }
};