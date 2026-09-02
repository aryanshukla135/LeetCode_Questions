class Solution {
private:
    int f(string & s ,string & t ,int i , int j , vector<vector<int>> & dp){

        if(i<0){
          return j+1;
        }
        if(j<0){
            return i +1;
        }


        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return  dp[i][j] =  0 + f(s,t,i-1,j-1,dp);
        }
        else{
            int ins = 1 + f(s,t,i,j-1,dp);
            int del = 1 + f(s,t,i-1,j,dp);
            int rep = 1 + f(s,t,i-1,j-1,dp);
            return dp[i][j]= min({ins,del,rep});
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(word1,word2,n-1,m-1,dp);
    }
};