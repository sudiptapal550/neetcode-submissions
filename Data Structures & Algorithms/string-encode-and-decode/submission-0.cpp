class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for (auto str: strs) {
            s += (to_string(str.length()) + "#" + str);
        }
        return s;
    }

    vector<string> decode(string s) {
    
        vector<string> ans;
        for (int i=0; i < s.length();i++) {
            int j = i;
            while (s[j] != '#') j+= 1;

            int len = stoi(s.substr(i, j - i));
            j = j + 1;
            ans.push_back(s.substr(j, len));
            i = j + len - 1;
        }
        return ans;
    }
};