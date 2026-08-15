class Solution {
private:
    int f(vector<vector<int>>& triangle,int i ,int j , int n ,int m,vector<vector<int>> &dp ){
        if(i == n-1) return triangle[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int d = triangle[i][j] + f(triangle,i+1,j,n,m,dp);
        int dg = triangle[i][j] + f(triangle,i+1,j+1,n,m,dp);

        return dp[i][j] =  min(d,dg);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
      //  int ans = f(triangle,0,0,n,m,dp);
        // tabulation 
        for(int i =0 ; i<triangle[n-1].size() ; i++){
            dp[n-1][i] = triangle[n-1][i];
        }

        for(int i = n-2 ; i>=0 ; i--){
            for(int j = i ; j>=0 ; j--){
                int d = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(d,dg);
            }
        }

        return dp[0][0] ;
    }
};