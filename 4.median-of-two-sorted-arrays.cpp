/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();
    double ans = 0;
    int k = (n + m) / 2;
    int l = 0, r = k;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      int x = k - mid;
      if (mid - 1 >= n) {
        r = mid - 1;
        continue;
      }
      if (x - 1 >= m) {
        l = mid + 1;
        continue;
      }
      if (mid > 0 && x < m) {
        if (nums1[mid - 1] > nums2[x]) {
          r = mid - 1;
          continue;
        }
      }
      if (x > 0 && mid < n) {
        if (nums2[x - 1] > nums1[mid]) {
          l = mid + 1;
          continue;
        }
      }
      if ((n + m) % 2) {
        int t1 = 1e9;
        if (mid < n) {
          t1 = nums1[mid];
        }
        if (x < m) {
          t1 = min(t1, nums2[x]);
        }
        ans = t1;
        break;
      } else {
        int t1 = 0, t2 = 1e9;
        if (mid) {
          t1 = nums1[mid - 1];
        }
        if (x) {
          t1 = max(t1, nums2[x - 1]);
        }
        if (mid < n) {
          t2 = nums1[mid];
        }
        if (x < m) {
          t2 = min(t2, nums2[x]);
        }
        ans = (double)(t1 + t2) / 2;
        break;
      }
    }
    return ans;
  }
};
// @lc code=end