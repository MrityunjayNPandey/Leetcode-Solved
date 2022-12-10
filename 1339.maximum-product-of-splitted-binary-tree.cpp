/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
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
  int mindiff = 1e9, sumst = 0;
  int sumtree(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    return sumtree(root->left) + sumtree(root->right) + root->val;
  }
  //backtracking
  int diffstree(TreeNode *root, int sumt) {
    if (root == NULL) {
      return 0;
    }
    int sum =
        diffstree(root->left, sumt) + diffstree(root->right, sumt) + root->val;
    if (abs(sumt - 2 * sum) < mindiff) {
      mindiff = abs(sumt - 2 * sum);
      sumst = sum;
    }
    return sum;
  }
  int maxProduct(TreeNode *root) {
    int sum = sumtree(root);
    int sum1 = diffstree(root, sum);
    int mod = 1e9 + 7;
    return ((long long)(sumst % mod) * (long long)((sum - sumst) % mod)) % mod;
  }
};
// @lc code=end
