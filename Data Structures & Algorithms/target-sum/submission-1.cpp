class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        // Edge cases: 
        // 1. If absolute target is greater than the total sum of the array.
        // 2. If (target + total_sum) is odd, it's impossible to divide into P and N.
        if (abs(target) > total_sum || (target + total_sum) % 2 != 0) {
            return 0;
        }
        
        // This is the subset sum we need to find
        int subset_sum = (target + total_sum) / 2;
        
        // dp[i] will store the number of ways to make sum 'i'
        vector<int> dp(subset_sum + 1, 0);
        dp[0] = 1; // There is 1 way to make a sum of 0 (pick nothing)
        
        // 0/1 Knapsack DP
        for (int num : nums) {
            // We iterate backwards to ensure we only use each number once per subset
            for (int i = subset_sum; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }
        
        return dp[subset_sum];
    }
};