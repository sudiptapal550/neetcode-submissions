class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // dp[i] strictly means: Max profit ending with a SALE EXACTLY on day i
        vector<int> dp(n, 0); 
        int ans = 0;

        for (int i = 0; i < n; i++) {
            
            // REMOVED: if (i > 0) dp[i] = dp[i-1];
            // We no longer carry forward the "do nothing" state.

            for (int j = 0; j < i; j++) {
                int current_trade_profit = prices[i] - prices[j];
                
                // Because dp array no longer holds the running maximum,
                // we must manually search for the best previous sale 
                // that happened on or before day j-2 (cooldown rule).
                int best_prev_profit = 0;
                for (int k = 0; k <= j - 2; k++) {
                    best_prev_profit = max(best_prev_profit, dp[k]);
                }
                
                // Update dp[i] using the best past sequence + current trade
                dp[i] = max(dp[i], current_trade_profit + best_prev_profit);
            }
            // Since the final best sale could happen on ANY day, 
            // we constantly track the overall maximum.
            ans = max(ans, dp[i]); 
        }
        return ans;
    }
};