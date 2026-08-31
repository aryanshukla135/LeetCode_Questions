class Solution {
private:
    int lcs(string &s , string &t , int i ,int j , vector<vector<int>> & dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = 1 + lcs(s,t,i-1,j-1,dp);
        }else{
            return dp[i][j] = max(lcs(s,t,i-1,j,dp),lcs(s,t,i,j-1,dp));
        }
    }
public:
    int minInsertions(string s) {
        int n = s.length();
        string t = s; 
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int maxlcs = lcs(s,t,n-1,n-1,dp);

        return n - maxlcs;

    }
};
// mbadm
// mdabm