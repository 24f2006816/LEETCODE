class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int bestDistance = INT_MAX;
        int answer = -1;
        for (int i = 0;  i < drones.size(); i++){
            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];
            int distance = abs(x-target[0]) + abs(y-target[1]);
            if (distance <= range && distance < bestDistance){
                bestDistance = distance;
                answer = i;
            }
        }
        return answer;
    }
};