class Solution {
private:
   int f(vector<vector<int>> & matrix , int i , int j,vector<vector<int>> & dp){
       if(j<0 || j>= matrix[0].size()) return 1e8;
       if(i == 0) return matrix[0][j];

       if(dp[i][j] != INT_MAX) return dp[i][j];

       int d = matrix[i][j] + f(matrix,i-1,j,dp);
       int ld = matrix[i][j] + f(matrix,i-1,j-1,dp);
       int rd = matrix[i][j] + f(matrix,i-1,j+1,dp);

       return dp[i][j] = min(d,min(ld,rd));
   }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));

        int mini = INT_MAX ;
        // for(int i =0 ; i<n ; i++){
        //     mini = min(mini ,f(matrix,n-1,i,dp));
        // }


        // tabulation 
        for(int i =0 ; i<n ; i++) dp[0][i] = matrix[0][i];

        for(int i =1 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                int d = INT_MAX;
                if(i-1 >=0) d = matrix[i][j] + dp[i-1][j];

                int ld = INT_MAX;
                if(i-1 >=0 && j-1 >= 0) ld = matrix[i][j] + dp[i-1][j-1];

                int rd = INT_MAX;
                if(i-1>=0 && j+1 < n) rd = matrix[i][j] + dp[i-1][j+1]; 

                dp[i][j] = min(d,min(ld,rd));

            }
        }
        for(int i =0 ; i<n ; i++){
            mini = min(mini,dp[n-1][i]);
        }
        return mini ;
    }
};