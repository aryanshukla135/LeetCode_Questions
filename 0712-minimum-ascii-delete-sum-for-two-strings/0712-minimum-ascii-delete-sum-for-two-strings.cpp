class Solution {
private:
    int f(string & s ,string & t ,int i , int j , vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0 ;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = (int)s[i] + f(s,t,i-1,j-1,dp);
        }else{
            return dp[i][j] = max(f(s,t,i-1,j,dp),f(s,t,i,j-1,dp));
        }
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        int notToDelete = f(s1,s2,n-1,m-1,dp);
        int totalascii1 = 0;
        for(int i =0 ; i<n ; i++){
            totalascii1 += (int)s1[i];
        }
        int totalascii2 = 0;
        for(int i =0 ; i<m ; i++){
            totalascii2 += (int)s2[i];
        }
        cout<<notToDelete;
        int total = (totalascii1 + totalascii2) - 2*notToDelete;
        return total;
        
    }
};