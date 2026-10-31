class Solution {
private:
    const int mod = 1e9 + 7 ;
    int solve(vector<vector<int>>& grid , int i ,int j,int state,vector<vector<vector<int>>>& dp){
        int n = grid.size();
        int m = grid[0].size();

        if(i >=n || j >= m){
            return 0 ;
        }
        if(i == n-1 && j == m-1){
            return 1 ;
        }
        if(dp[i][j][state] != -1){
            return dp[i][j][state];
        }
        int down = 0;
        int right = 0;

        if(grid[i][j] == 1){
            if(state == 1 ){
              down = solve(grid,i+1,j,0,dp);
            }else{
              right = solve(grid,i,j+1,1,dp);
            }
        }else{
            right = solve(grid,i,j+1,1,dp);
            down = solve(grid,i+1,j,0,dp);
        }
        return dp[i][j][state] = ((right + down) % mod) ;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        // state = 1 => right 
        // state = 0 => down 
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(2,-1)));

        int ans = solve(grid,0,0,0,dp);
        return ans ;
    }
};