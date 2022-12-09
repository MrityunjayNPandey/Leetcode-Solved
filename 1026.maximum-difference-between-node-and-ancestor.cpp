/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int k = 0;
  int maxAncestorDiff(TreeNode *root) {
    return func(root, root->val, root->val);
  }
  int func(TreeNode *root, int maxn, int minn) {
    if (root == NULL) {
      return 0;
    }
    int temp = max({abs(root->val - maxn), abs(root->val - minn)});
    maxn = max(maxn, root->val);
    minn = min(minn, root->val);
    int left = func(root->left, maxn, minn);
    int right = func(root->right, maxn, minn);
    return max({temp, left, right});
  }
};
// @lc code=end
