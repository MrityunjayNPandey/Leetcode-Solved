/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
public:
  string convert(string s, int numRows) {
    int n = s.length();
    string res;
    vector<string> vv(numRows);
    if(numRows==1)
    return s;
    int r = 0, c = 0, k = 0;
    for (int i = 0; i < n; i++) {
      vv[r] += s[i];
      if (c == (numRows - 1) * k) {
        r++;
        if (r == numRows) {
          k++;
          r -= 2;
          c++;
        }
      } else {
        r--;
        c++;
      }
    }
    for (auto i : vv) {
          res += i;
    }
    return res;
  }
};
// @lc code=end