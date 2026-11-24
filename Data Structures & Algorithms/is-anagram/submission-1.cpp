class Solution {
public:
    bool isAnagram(string s, string t) {
        // early return
        if(s.size() != t.size()) return false;

        unordered_map<char, int> freqsS;
        unordered_map<char, int> freqsT;
        for(int i = 0; i < s.size(); i++) {
            freqsS[s[i]]++;
            freqsT[t[i]]++;
        }

        return freqsS == freqsT;
    }
};
