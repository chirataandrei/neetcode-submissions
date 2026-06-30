class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            int cost1 = (i > 0 ? dp[i - 1] : 0) + costs[0];
            int j7 = i;
            while (j7 >= 0 && days[i] - days[j7] < 7) {
                j7--;
            }
            int cost7 = (j7 >= 0 ? dp[j7] : 0) + costs[1];
            int j30 = i;
            while (j30 >= 0 && days[i] - days[j30] < 30) {
                j30--;
            }
            int cost30 = (j30 >= 0 ? dp[j30] : 0) + costs[2];
            dp[i] = min({cost1, cost7, cost30});
        }
        return dp[n - 1];
    }
};