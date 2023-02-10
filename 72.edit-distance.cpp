/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
  int dp[501][501]{};
  int minDistance(string &str1, string &str2, int p = 0, int q = 0) {
    int n = str1.length(), m = str2.length();
    if (n == 0) {
      return m;
    }
    if (m == 0) {
      return n;
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
      dp[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
      dp[0][i] = i;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (str1[i - 1] != str2[j - 1]) {
          dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
        } else {
          dp[i][j] = dp[i - 1][j - 1];
        }
      }
    }
    return dp[n][m];
  }
};
// @lc code=end
