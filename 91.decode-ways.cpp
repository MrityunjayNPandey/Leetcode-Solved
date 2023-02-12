/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    if (n == 0 || s[0] == '0')
      return 0;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
      string str;
      str += s[i];
      str += s[i + 1];
      int t = stol(str);
      if (s[i] == '0' && s[i + 1] == '0') {
        return 0;
      }
      if (s[i] != '0') {
        if (s[i + 1] == '0') {
          if (t > 26)
            return 0;
          if (i + 2 <= n)
            dp[i + 2] += dp[i];
        } else if (t <= 26) {
          dp[i + 1] += dp[i];
          if (i + 2 <= n)
            dp[i + 2] += dp[i];
        } else {
          dp[i + 1] += dp[i];
        }
      }
    }
    return dp[n];
  }
};
// @lc code=end
