class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> myMap;
        for(int i = 0; i < nums.size(); i++) {
            if(myMap[nums[i]]) {
                return true;
            }
            myMap[nums[i]] = true;
        }
        return false;
    }
};