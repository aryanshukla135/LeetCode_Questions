class Solution {
private:
    int solve(vector<int>& cost, vector<int>& time, int ind, int rem,vector<vector<int>> & dp) {
        if(rem <= 0){
            return 0;
        }
        if (ind == cost.size())
            return 1e9;
        
        if(dp[ind][rem] != -1){
            return dp[ind][rem];
        }

        int paid = cost[ind] + solve(cost, time, ind + 1, rem -1- time[ind],dp);

        int free = solve(cost, time, ind + 1, rem,dp);
   

        return dp[ind][rem]= min(paid, free);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(cost,time,0,n,dp);
    }
};