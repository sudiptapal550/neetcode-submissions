class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = 0;
        for (int num : nums) total_sum += num;
        
        // If the target is completely out of reach, return 0
        if (abs(target) > total_sum) return 0;
        
        // To handle negative sums, we shift all our array indexes by 'total_sum'.
        // So a sum of 0 will be stored at dp[total_sum].
        int offset = total_sum;
        vector<int> dp(2 * total_sum + 1, 0);
        
        // Base case: 1 way to make a sum of 0
        dp[0 + offset] = 1;
        
        // 1. MUST iterate over the numbers FIRST so we only use each one exactly once
        for (int i = 0; i < nums.size(); i++) {
            
            // We use a temporary array for the next state so we don't accidentally 
            // use the newly updated values in the same step.
            vector<int> next_dp(2 * total_sum + 1, 0);
            
            // 2. Iterate through all possible sums we could have made so far
            for (int current_sum = -total_sum; current_sum <= total_sum; current_sum++) {
                
                // If there is at least 1 way to reach this current_sum...
                if (dp[current_sum + offset] > 0) {
                    
                    // ...branch 1: ADD the current number
                    next_dp[current_sum + nums[i] + offset] += dp[current_sum + offset];
                    
                    // ...branch 2: SUBTRACT the current number
                    next_dp[current_sum - nums[i] + offset] += dp[current_sum + offset];
                }
            }
            // Move to the next day / state
            dp = next_dp;
        }
        
        // Return the number of ways we reached the specific target
        return dp[target + offset];
    }
};