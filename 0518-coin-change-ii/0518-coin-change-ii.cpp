class Solution {
private:
    int f(vector<int> & coins , int target , int  ind,vector<vector<int>> &dp){
        if(ind == 0){
            return (target % coins[ind] == 0);
        }
        if(dp[ind][target] != -1) return dp[ind][target];

        int nottake = f(coins,target,ind-1,dp);

        int take =0 ;

        if(coins[ind] <= target) take = f(coins,target-coins[ind],ind,dp);

        return dp[ind][target] = take + nottake ;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        return f(coins,amount,n-1,dp);
    }
};