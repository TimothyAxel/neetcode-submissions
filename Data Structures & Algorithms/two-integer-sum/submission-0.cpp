class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // calculate target
        // calculate map
        unordered_map<int, int> seen; //key: number, value: index
        for(int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            int remaining = target - curr;
            if(seen.contains(remaining)) {
                return {seen[remaining], i};
            }
            seen[curr] = i;
        }
        // not possible, always one pair of indices
    }
};
