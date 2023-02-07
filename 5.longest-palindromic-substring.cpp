/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.length(), ans = 0;
    string sans;
    for (int i = 0; i < n; i++) {
      // consider every character as a palindrome and then make a
      // palinrome string around it
      int k = 0;
      while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
        k++;
      }
      k--;
      if (2 * k + 1 > ans) {
        ans = 2 * k + 1;
        sans = s.substr(i - k, ans);
      }
      k = 0;
      while (i - k >= 0 && i + 1 + k < n && s[i - k] == s[i + 1 + k]) {
        k++;
      }
      k--;
      if (2 * (k + 1) > ans) {
        ans = 2 * (k + 1);
        sans = s.substr(i - k, ans);
      }
    }
    return sans;
  }
};
// @lc code=end
