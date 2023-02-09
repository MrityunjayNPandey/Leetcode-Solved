/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
  int longestValidParentheses(string s) {
    int n = s.length();
    int ans = 0;
    stack<pair<char, int>> st;
    for (int j = 0; j < n; j++) {
      if (s[j] == '(')
        st.push({s[j], j});
      else {
        if (!st.empty() && st.top().first == '(') {
          st.pop();
          if (!st.empty() && ans < j - st.top().second + 1) {
            ans = max(ans, j - st.top().second + 1);
          } else {
            ans = max(ans, j - 1);
          }
        } else {
          st.push({s[j], j});
        }
      }
    }
    return ans;
  }
};
// @lc code=end
