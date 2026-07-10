class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum_max = 0;
        for (int x : nums) sum_max += x;
        if (abs(target) > sum_max) return 0;
        int total = 1 + 2 * sum_max;
        vector<vector<int>> dp(n, vector<int> (total, 0));
        dp[0][sum_max - nums[0]] += 1;
        dp[0][sum_max + nums[0]] += 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < total; j++) {
                if (dp[i - 1][j] > 0) {
                    dp[i][j - nums[i]] += dp[i - 1][j];
                    dp[i][j + nums[i]] += dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target + sum_max];
    }
};
