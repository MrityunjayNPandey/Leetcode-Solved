// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem96.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
  int numTrees(int n) {
    int ans = 0;
    vector<int> dp(n + 1, 1);
    for (int i = 1; i <= n; i++) {
      ans=0;
      for (int j = 1; j <= i; j++) {
        ans += dp[j - 1] * dp[i - j];
      }
      dp[i] = ans;
    }
    return dp[n];
  }
};
// @lc code=end
