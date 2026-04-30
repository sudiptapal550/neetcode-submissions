class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector<vector<int>> dp(n+1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }

        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < m; j++) {
                if (s[j] == t[i]) {
                    dp[i+1][j+1] += dp[i][j];
                }
                dp[i+1][j+1] += dp[i+1][j];
            }
        }
        return dp[n][m];
        
    }
};
