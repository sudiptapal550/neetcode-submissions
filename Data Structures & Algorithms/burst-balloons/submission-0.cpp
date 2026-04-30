class Solution {
public:
    int maxCoins(vector<int>& nums) {
       nums.push_back(1);
       nums.insert(nums.begin(), 1); 
       int n = nums.size();
       vector<vector<int>> dp(n, vector<int>(n, 0));

       
       for (int l = 1; l <= n; l++) {
          for (int i = 0; i + l - 1 < n; i++) {
            int j = i + l - 1;
            for (int k = i + 1 ; k < j; k++) {
                dp[i][j] = max(dp[i][j], nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]);
            }
          } 
        }
        return dp[0][n-1];
    }
};
