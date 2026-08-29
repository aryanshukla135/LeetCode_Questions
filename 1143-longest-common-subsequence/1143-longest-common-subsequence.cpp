class Solution {
private:
    int f(string & s ,string & t , int ind1 , int ind2 , vector<vector<int>> & dp){
        if(ind1 == 0 || ind2 == 0){
            return 0;
        }

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(s[ind1-1] == t[ind2-1]){
            return dp[ind1][ind2] = 1 + f(s,t,ind1-1,ind2-1,dp);
        }
        return dp[ind1][ind2] =  max(f(s,t,ind1-1,ind2,dp) , f(s,t,ind1,ind2-1,dp));
    }
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
     //   int ans =  f(s,t,n,m,dp);
          for(int i =0 ; i<m ; i++){
             dp[0][i] = 0;
          }

           for(int i =0 ; i<n ; i++){
             dp[i][0] = 0;
          }

          for(int i = 1 ; i<=n ; i++){
             for(int j = 1 ; j<=m ; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
             }
          }

        // for(int i =0 ; i< n ; i++){
        //     for(int j = 0 ;j<m ; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        int ans = dp[n][m];
        if(ans< 0) return 0 ;
        return ans ;

       
    }
};