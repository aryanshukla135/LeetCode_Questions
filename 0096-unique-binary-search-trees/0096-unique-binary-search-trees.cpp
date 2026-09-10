class Solution {
private:
    int solve(int n,vector<int> & dp ){
        if(n<=1){
            return 1;
        }
        if(dp[n] != -1 ) return dp[n];
        int cnt = 0;
         
        for(int i =0 ; i<n ;i++){
            cnt += solve(i,dp) * solve(n-i-1,dp);
        }
        return dp[n] = cnt ;
    }

public:
    int numTrees(int n){
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};