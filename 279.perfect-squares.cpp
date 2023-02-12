// @before-stub-for-debug-begin
#include "commoncppproblem279.h"
#include <bits/stdc++.h>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
  int dp[10005]{};
  int numSquares(int n) {
    if (n == 0) {
      return 0;
    }
    if(dp[n])
      return dp[n];
    int p = sqrt(n);
    int ans = 1e9;
    for (int i = p; i >= 1; i--) {
      int q = numSquares(n - i * i) + 1;
      ans = min(ans, q);
    }
    return dp[n]=ans;
  }
};
// @lc code=end
