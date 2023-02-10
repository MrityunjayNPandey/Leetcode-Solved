/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
  int minPathSum(vector<vector<int>> &grid, int i = 0, int j = 0) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 1e5));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i) {
          dp[i][j] = dp[i - 1][j] + grid[i][j];
        }
        if (j) {
          dp[i][j] = min((dp[i][j - 1] + grid[i][j]), dp[i][j]);
        }
      }
    }
    return dp[n - 1][m - 1];
  }
};
// @lc code=end
