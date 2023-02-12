/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    // i, pick, k
    int p1n = 0, p1 = 0, p2n = 0, p2 = 0, p3n = 0, p3 = 0, p4n = 0, p4 = 0,
        p5n = 0, p5 = 0;
    for (int i = n - 1; i >= 0; i--) {
      p3 = max(p1n + prices[i], p3n);
      p2 = max(p3n - prices[i], p2n);
      p4 = max(p2n + prices[i], p4n);
      p5 = max(p4n - prices[i], p5n);
      p2n = p2, p3n = p3, p4n = p4, p5n = p5;
    }
    return p5;
  }
};
// @lc code=end
