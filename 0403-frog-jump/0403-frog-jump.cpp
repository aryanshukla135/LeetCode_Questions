class Solution {
private:
    bool solve(vector<int> & stones , int idx, int prevjump,vector<vector<int>> &dp){
        if(idx == stones.size()-1) return true;
        if(dp[idx][prevjump] != -1) return dp[idx][prevjump];
        
        for(int i = -1 ; i<=1 ; i++){
            int nextjump = prevjump+i;
        
            for(int j = idx +1 ; j<stones.size() ; j++){
                int val = stones[j] - stones[idx];
                if(val == nextjump){
                   if(solve(stones,j,nextjump,dp) == true){
                     return dp[idx][prevjump] = true;
                   }
                }

            }

        }
        return dp[idx][prevjump] = false ;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
    
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(stones,0,0,dp);
    }
};