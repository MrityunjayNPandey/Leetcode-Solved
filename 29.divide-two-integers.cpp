/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
  int divide(int dividend, int divisor) {
    unsigned int ans = 0, p = 0;
    if (divisor < 0) {
      p++;
      divisor = -divisor;
    }
    if (dividend < 0) {
      p++;
      dividend = -dividend;
    }
    while (divisor <= dividend) {
      int k = 0;
      while ((divisor << k) <= dividend) {
        k++;
      }
      k--;
      dividend -= divisor << k;
      ans += 1LL << k;
    }
    return (p == 1) ? -((ans == (1LL << 31)) ? ((1LL << 31) - 1) : ans) : ans;
  }
};
// @lc code=end
