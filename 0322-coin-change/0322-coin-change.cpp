class Solution {
private:
    int f(vector<int> & coins, int i , int target,vector<vector<int>> &dp){
        if(i ==0 ){
            if(target % coins[i] == 0){
                return target/coins[i];
            }else{
                return 1e9;
            }
        }
        if(dp[i][target] != -1 ) return dp[i][target];
        int nottake = 0 + f(coins,i-1,target,dp);
        int take = 1e9 ;

        if(target >= coins[i]){
            take = 1 + f(coins,i,target - coins[i],dp);
        }
        return dp[i][target] =  min(take,nottake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
         int n = coins.size();
         vector<vector<int>> dp(n,vector<int>(amount+1,-1));
         // momorization 
        // int ans = f(coins,n-1,amount,dp);

         // taboulation 
         for(int t = 0 ; t <= amount ; t++){
            if(t % coins[0] == 0){
                dp[0][t] = t / coins[0];
            }else{
                dp[0][t] = 1e9;
            }
         }

         for(int i = 1 ; i<n ; i++){
            for(int t =0 ; t <= amount; t++){
                int nottake = 0 + dp[i-1][t];
                int take = 1e9 ;

                if(t >= coins[i]){
                    take = 1 + dp[i][t - coins[i]];
                }
                dp[i][t] =  min(take,nottake);
            }
         }
         int ans = dp[n-1][amount];
         if(ans == 1e9) return -1;

         return ans ;
    }
};