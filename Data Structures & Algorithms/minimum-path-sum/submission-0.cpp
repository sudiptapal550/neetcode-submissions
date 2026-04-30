class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 1e8));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n ; j++) {
                if (i == 0 && j == 0) {
                    dp[i+1][j+1] = grid[i][j];
                } else {
                    dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j]) + grid[i][j];
                }
            }
        }

        return dp[m][n];
        
    }
};