class Solution {
public:
    // limitation: ascii <-- need something beyond
    // 5___|6_____|
    // string length is below 200, so need 3 digits for prefix

    string encode(vector<string>& strs) {
        string res;
        for(string str : strs) {
            //prefix with how long the string is supposed to be, then append the str
            res += format("{:03}", str.size());
            res += str;
        }

        cout<<"res:"<<res<<endl;

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        long i = 0;
        while(i < s.size()) {
            // extract prefix
            long strLength = std::stol(s.substr(i, 3));

            // extract string
            long strStart = i + 3;
            res.push_back(
                s.substr(strStart, strLength)
            );

            // update iterator
            i += 3 + strLength; // offset by 3 because of prefix
        }

        return res;
    }
};
