/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size(), ans = 0;
    vector<int> start(n + 1, 1e9), end(n + 1);
    for (int i = 0; i < n; i++) {
      start[i + 1] = min(start[i], prices[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
      end[i] = max(end[i + 1], prices[i]);
    }
    for (int i = 1; i <= n; i++) {
      ans = max(ans, end[i] - start[i]);
    }
    return ans;
  }
};
// @lc code=end
