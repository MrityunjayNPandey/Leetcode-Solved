/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
  int rangeSumBST(TreeNode *root, int low, int high) {
    int left = 0, right = 0, x = 0;
    if (root == NULL)
      return 0;
    if (root->val >= low && root->val <= high)
      x = root->val;
    if (root->val >= high) {
      left = rangeSumBST(root->left, low, high);
    } else if (root->val <= low) {
      right = rangeSumBST(root->right, low, high);
    } else {
      left = rangeSumBST(root->left, low, high);
      right = rangeSumBST(root->right, low, high);
    }
    return left + right + x;
  }
};
// @lc code=end
