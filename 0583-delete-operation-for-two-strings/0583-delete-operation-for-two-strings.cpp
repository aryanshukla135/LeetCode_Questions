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
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        int notToDelete = lcs(word1,word2,n-1,m-1,dp);
        return (n-notToDelete) + (m -notToDelete);
    }
};