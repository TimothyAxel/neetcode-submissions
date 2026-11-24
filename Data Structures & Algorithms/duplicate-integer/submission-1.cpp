#include <unordered_map>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // create frequency table / set
        unordered_map<int, int> freqs;
        // add all nums into set
        for (int i = 0; i < nums.size(); i++) {
            if (freqs.contains(nums[i])) {
                return true;
            }
            freqs[nums[i]]++;
        }
        return false;
    }
};