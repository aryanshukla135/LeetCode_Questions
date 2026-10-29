class Solution {
private:
    int solve(vector<int>& price ,int i,vector<int>& dp ){
        if( i >= price.size()){
            return 0 ;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int mini = INT_MAX;
        for(int ind = 1 ; ind <= i + 2 ; ind++){
            int toind = i + ind ;
            mini = min(mini,price[i] + solve(price , toind,dp));
        }
        return dp[i] = mini ;
    }
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n,-1);
        int ans = solve(prices,0,dp);

        return ans ;
    }
};