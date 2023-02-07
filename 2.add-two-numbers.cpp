/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *list1 = l1, *list2 = l2;
    ListNode *ans = new ListNode();
    ListNode *res = ans;
    int sum = 0;
    while (list1 || list2 || sum) {
      if (list1) {
        sum += list1->val;
        list1 = list1->next;
      }
      if (list2) {
        sum += list2->val;
        list2 = list2->next;
      }
      ans->val = sum % 10;
      sum /= 10;
      if (list1 || list2 || sum) {
        ans->next = new ListNode();
        ans = ans->next;
      }
    }
    return res;
  }
};
// @lc code=end
