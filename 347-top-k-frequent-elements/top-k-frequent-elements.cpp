class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums){
            freq[num]++;
        }
        priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        > minHeap;

        for (auto& p : freq){
            int num = p.first;
            int frequency = p.second;
            minHeap.push({frequency, num});
            if (minHeap.size() > k){
                minHeap.pop();
            }
        }
        vector<int> result;
        while (!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};