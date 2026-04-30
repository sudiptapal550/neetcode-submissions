class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (i > 0) dp[i] = dp[i-1];
            for (int j = 0; j < i; j++) {
                dp[i] = max(dp[i], prices[i] - prices[j] + (j >= 2 ? dp[j - 2] : 0));
                ans = max(ans, dp[i]);
            }
        }
        return ans;
        
    }
};
