class Solution {
private:
    int f(vector<int> &prices,int ind , int buy,vector<vector<int>> & dp){
        if(ind == prices.size()){
            return 0 ;
        }

        if(dp[ind][buy] != -1) return dp[ind][buy];
        int ans =0 ;
        if(buy == 1){
           int buy = -prices[ind] + f(prices,ind+1,0,dp);
           int notbuy = 0 + f(prices,ind+1,1,dp);
           ans = max(buy,notbuy);
        }else{
           int sell = prices[ind] + f(prices,ind +1 ,1,dp);
           int notsell = 0 + f(prices,ind+1,0,dp);
           ans = max(sell ,notsell);
        }
        return dp[ind][buy] = ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(prices,0,1,dp);
    }
};