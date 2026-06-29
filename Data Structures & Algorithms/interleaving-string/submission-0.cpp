#include <vector>

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), p = s3.size();
        if (n + m != p) {
            return false;
        }
        vector<vector<bool>> dp(n + 1, vector<bool> (m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {    
            if (s1[i - 1] == s3[i - 1] && dp[i - 1][0] == true) {
                dp[i][0] = true;
            }
        }
        for (int i = 1; i <= m; i++) {
            if (s2[i - 1] == s3[i - 1] && dp[0][i - 1] == true) {
                dp[0][i] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j] == true) {
                    dp[i][j] = true;
                } else if (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1] == true) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[n][m];
    }
};