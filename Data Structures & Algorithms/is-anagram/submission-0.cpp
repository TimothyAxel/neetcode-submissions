class Solution {
public:
    bool isAnagram(string s, string t) {
        // 0. check length
        if(s.length() != t.length()) {
            return false;
        }
        // 1. generate freq map of s
        unordered_map<char, int> freq;
        for(char c : s) {
            freq[c]++;
        }

        // check t through freq map 
        for (char c : t) {
            if (freq[c] <= 0) {
                return false;
            }
            freq[c]--;
        }

        return true;
    }
};
