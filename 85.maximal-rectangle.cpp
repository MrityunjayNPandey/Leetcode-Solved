/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
public:
  // O(n*n*m)
  int maximalRectangle(vector<vector<char>> &matrix) {
    int n = matrix.size(), m = matrix[0].size(), ans = 0;
    vector<vector<tuple<int, int, int>>> vv(n, vector<tuple<int, int, int>>(m));
    for (int i = 0; i < n; i++) {
      for (int j = m - 1; j >= 0; j--) {
        if (j == m - 1) {
          get<0>(vv[i][j]) = (matrix[i][j] == '1') ? 1 : 0;
          continue;
        }
        if (matrix[i][j] == '1')
          get<0>(vv[i][j]) += get<0>(vv[i][j + 1]) + 1;
        else
          get<0>(vv[i][j]) = 0;
      }
    }
    for (int j = 0; j < m; j++) {
      vector<int> v;
      for (int i = 0; i < n; i++) {
        v.push_back(get<0>(vv[i][j]));
      }
      // Nearest Smaller elements O(n)
      // vNSE[i]={{prev_smallest_value, prev_smallest_index},
      // {next_smallest_value, next_smallest_index}}
      vector<pair<pair<int, int>, pair<int, int>>> vNSE(n, {{-1, -1}, {-1, n}});
      function<void(int)> NSE = [&](int n) {
        stack<pair<int, int>> S, S1;
        for (int i = 0; i < n; i++) {
          while (!S.empty() && S.top().first >= v[i])
            S.pop();
          if (!S.empty())
            vNSE[i] = {S.top(), vNSE[i].second};
          S.push({v[i], i});
        }
        for (int i = n - 1; i >= 0; i--) {
          while (!S1.empty() && S1.top().first >= v[i])
            S1.pop();
          if (!S1.empty())
            vNSE[i] = {vNSE[i].first, S1.top()};
          S1.push({v[i], i});
        }
      };
      NSE(n);
      for (int i = 0; i < n; i++) {
        get<1>(vv[i][j]) = vNSE[i].first.second;
        get<2>(vv[i][j]) = vNSE[i].second.second;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans = max(ans, get<0>(vv[i][j]) * (i - get<1>(vv[i][j]) + get<2>(vv[i][j]) - j - 1));
      }
    }
    return ans;
  }
};
// @lc code=end
