class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs; // key: num, value: frequency
        for(auto& n : nums) {
            freqs[n]++;
        }

        // use priorityqueue
        priority_queue<pair<int, int>> pq; // 1: frequency, 2: num
        for(auto& p : freqs) {
            pq.push({p.second, p.first});
        }
        
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
