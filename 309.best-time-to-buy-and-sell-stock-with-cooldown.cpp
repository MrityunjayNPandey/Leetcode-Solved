// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
  int maxProfit(vector<int> &prices, int ind = 0, int pick = 0) {
    int n = prices.size();
    for (int i = n; i >= 1; i--) {
      dp[i-1][1]=max(dp[i][0]+prices[i-1], dp[i-1][1]);
      dp[i-1][0]=max(dp[i][0], dp[i-1][0]);
      if(i>=2)
        dp[i-2][0]=max(dp[i][1]-prices[i-1], dp[i-2][0]);
      dp[i-1][1]=max(dp[i][1], dp[i-1][1]);
      if(i==1){
        dp[i-1][0]=max(dp[i][1]-prices[i-1], dp[i-1][0]);
      }
    }
    return dp[0][0];
  }
  signed main(){
    vector<int> v={1, 2, 3, 0, 2};
    int p=maxProfit(v);
    return 0;
  }
// @lc code=end
