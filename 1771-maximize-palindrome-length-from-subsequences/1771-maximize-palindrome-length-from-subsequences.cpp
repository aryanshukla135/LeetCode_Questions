class Solution {
private:
    int lps(string & s,int i, int j,vector<vector<int>> & dp) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        
        int res;
        if (s[i] == s[j]) {
            res = lps(s,i + 1, j - 1,dp) + 2;
        } else {
            res = max(lps(s,i + 1, j,dp), lps(s,i, j - 1,dp));
        }
        
        return dp[i][j] = res;
    }
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2 ;
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int n1 =word1.size();

        int ans = 0;
        for(int i =0 ; i<n1 ; i++){
            for(int j = n1 ; j<n ;j++){
                if(s[i] == s[j]){
                  ans = max(ans, lps(s,i,j,dp));
                }
            }
        }
        return ans ;
    }
};