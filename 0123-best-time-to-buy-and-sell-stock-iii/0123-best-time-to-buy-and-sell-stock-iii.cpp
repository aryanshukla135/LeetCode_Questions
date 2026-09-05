class Solution {
private:
    int f(vector<int> & prices, int ind , int buy , int capicity,vector<vector<vector<int>>>& dp){
        if(ind == prices.size() || capicity == 0){
            return 0 ;
        }

        if(dp[ind][buy][capicity] != -1) return dp[ind][buy][capicity]; 
 
        if(buy == 1){
           return dp[ind][buy][capicity] = max(-prices[ind] + f(prices, ind +1, 0 , capicity,dp), 0 + f(prices,ind+1,1,capicity,dp));
        }
        return dp[ind][buy][capicity] =  max(prices[ind] + f(prices, ind +1, 1 , capicity - 1,dp), 0 + f(prices,ind+1,0,capicity, dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        
        int ans = f(prices,0,1,2,dp);
        return ans ;
    }
};