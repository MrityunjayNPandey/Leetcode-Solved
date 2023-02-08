/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
  int reverse(int x) {
    string str = to_string(x);
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
      swap(str[i], str[n - 1 - i]);
    }
    return stoi(str);
  }
};
// @lc code=end
