class Solution {
private:
    long long solve(vector<vector<int>> &  questions , int idx,vector<long long>&dp){
        int n = questions.size();
        int m = questions[0].size();
        if(idx > n ) return 0 ;
        if(idx == n-1 ){
            return questions[idx][0];
        }
        if(dp[idx] != -1) return dp[idx];
        long long take = INT_MIN;
        if(idx < n){
           long long val = questions[idx][0];
           int toskip = questions[idx][1];
           take = val + solve(questions,toskip + idx +1,dp);
        }
        long long nottake = 0 + solve(questions,idx+1,dp);
       

        return dp[idx] = max(take,nottake);

    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
         int n = questions.size();
         vector<long long> dp(n+1,-1);
         long long ans = solve(questions,0,dp);
         return ans ;
    }
};