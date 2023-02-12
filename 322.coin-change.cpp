// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end
int func(vector<int>& coins,vector<int> &dp, int amount){
        int ans=1e9;
        if(amount==0){
          return dp[amount]=0;
        }
        if(dp[amount]!=1e9)
          return dp[amount];
        for(int i=0; i<coins.size(); i++){
          if(amount-coins[i]>=0)
            ans = min(ans, func(coins, dp, amount-coins[i])+1);
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);
        int k=func(coins,dp, amount);
        if(k==1e9)
          return -1;
        return k;
    }
signed main(){
  vector<int> v={186,419,83,408};
  int p=coinChange(v, 6249);
  return 0;
}
// @lc code=end

