class Solution {
public:
    using Counts = unordered_map<char, int>;

    struct CountsHash {
        size_t operator()(const Counts& m) const {
            size_t h = 0;
            for (const auto& [c, n] : m) {
                size_t eh = hash<char>{}(c);
                eh ^= hash<int>{}(n) + 0x9e3779b9 + (eh << 6) + (eh >> 2);
                h += eh;   // commutative, so iteration order doesn't matter
            }
            return h;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // use freq map for identity of hashmap
        unordered_map<Counts, vector<string>, CountsHash> freqToStrs;
        vector<vector<string>> res;

        // create freq maps for each str, use as identity to a map
        for(int i = 0; i < strs.size(); i++) {
            string currStr = strs[i]; 
            unordered_map<char, int> currFreqs;

            // inner loop: create freq map to use as identity
            for(int j = 0; j < currStr.size(); j++) {
                currFreqs[currStr[j]]++;
            }
            
            freqToStrs[currFreqs].push_back(currStr);
        }

        // iterate through freq map
        for (const auto& [mapKey, mapVal] : freqToStrs) {
            res.push_back(mapVal);
        }

        return res;
    }
};
