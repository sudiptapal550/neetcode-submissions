class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r = 0;
        int l = 0;
        int ans = 0;
        unordered_map<char,int> mp;
        while ( r < s.length()) {
            while(l < r && mp[s[r]] >= 1) {
                mp[s[l++]] -= 1;
            }
            ans = max(ans, r - l + 1);
            mp[s[r]] += 1;
            r += 1;
        }
        return ans; 
    }
};