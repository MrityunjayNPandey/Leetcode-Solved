/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> ump;
    int init = 0, n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (ump.count(s[i]) && ump[s[i]] >= init) {
        init = ump[s[i]] + 1;
      }
      ans = max(ans, i - init + 1);
      ump[s[i]] = i;
    }
    return ans;
  }
};
// @lc code=end
