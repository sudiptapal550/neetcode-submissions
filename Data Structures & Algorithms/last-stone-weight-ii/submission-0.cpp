class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);

        int target = sum / 2;

        vector<vector<int>> dp(n+1, vector<int>(target + 1, 0));


        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i+1][j] = dp[i][j];

                if (j >= stones[i]) {
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j - stones[i]] + stones[i]);
                }
            }
        }
        return sum - 2*dp[n][target];
    }
};