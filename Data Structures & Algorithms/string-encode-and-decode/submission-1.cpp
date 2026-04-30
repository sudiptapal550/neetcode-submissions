class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (auto str: strs) {
            res += (to_string(str.length()) + ":" + str);
        }

        return res;
    }


    vector<string> decode(string s) {

        vector<string> ans;
        int ind = 0;

        while (ind < s.length()) {
            string val = "";
            while (s[ind] != ':') {
                val += s[ind];
                ind += 1;
            }
            //cout << val << endl;
            ind += 1;
            ans.push_back(s.substr(ind, stoi(val)));
            ind += stoi(val);
        }
        return ans;
    }
};
