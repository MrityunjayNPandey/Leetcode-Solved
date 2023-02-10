/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
  int dp[101][101]{};
  int uniquePathsWithObstacles(vector<vector<int>> &vv) {
    int n = vv.size(), m = vv[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 0));
    dp[0][0]=1;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(i>0)
          dp[i][j]+=dp[i-1][j];
        if(j>0)
          dp[i][j]+=dp[i][j-1];
        if(vv[i][j]==1)
          dp[i][j]=0;     
      }
    }
    return dp[n-1][m-1];
  }
};
// @lc code=end
