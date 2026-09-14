class Solution {
public:
    string longestPalindrome(string s) {
         int n = s.length();
         vector<vector<bool>> dp(n , vector<bool>(n , 0));
           
         int maxlen =1 ;
         int start = 0;

         for(int i = n-1 ; i>=0 ; i--){
            for(int j = i ; j<n ; j++ ){
                if(s[i] == s[j]){
                   if(j-i<=1){
                     dp[i][j] = true;
                   }else{
                     dp[i][j] = dp[i+1][j-1];
                   }
                }
                if(dp[i][j]){
                    int len = j-i+1;
                    if(len > maxlen ){
                        maxlen = len ;
                        start = i;
                    }
                }
            }
         }
         
         string ans = s.substr(start,maxlen);
         return ans ;
    }
};