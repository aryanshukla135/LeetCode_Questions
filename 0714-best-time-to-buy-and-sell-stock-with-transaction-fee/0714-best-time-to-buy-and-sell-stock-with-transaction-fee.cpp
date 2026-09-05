class Solution {
 int f(vector<int> & prices,int ind ,int buy,vector<vector<int>> & dp,int fee){
        if(ind >= prices.size()){
            return 0 ;
        }
        if(dp[ind][buy] != -1) return dp[ind][buy];

        if(buy){
            return dp[ind][buy] = max(-prices[ind] + f(prices,ind +1,0,dp,fee) , 0 + f(prices , ind +1 , 1,dp,fee));
        }

        return dp[ind][buy] = max(prices[ind] - fee + f(prices,ind +1,1,dp,fee) , 0 + f(prices , ind +1 , 0,dp,fee));
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));

        int ans = f(prices,0,1,dp,fee);
        return ans;
    }
};