class Solution {
private:
    int f(string & s ,string & t , int ind1 , int ind2 , vector<vector<int>> & dp){
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(s[ind1] == t[ind2]){
            return dp[ind1][ind2] = 1 + f(s,t,ind1-1,ind2-1,dp);
        }
        return dp[ind1][ind2] =  max(f(s,t,ind1-1,ind2,dp) , f(s,t,ind1,ind2-1,dp));
    }
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(s,t,n-1,m-1,dp);
    }
};