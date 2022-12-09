/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int n = nums.size();
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++) {
      vp[i] = {nums[i], i};
    }
    sort(vp.begin(), vp.end());
    int l = 0, r = n - 1;
    vector<int> vans;
    while (l < r) {
      if (vp[l].first + vp[r].first > target)
        r--;
      else if (vp[l].first + vp[r].first < target)
        l++;
      else {
        vans.push_back(vp[l].second);
        vans.push_back(vp[r].second);
        break;
      }
    }
    return vans;
  }
};
// @lc code=end
