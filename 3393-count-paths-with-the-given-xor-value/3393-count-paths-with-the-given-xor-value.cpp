class Solution {
private:
    int mod = 1e9 + 7 ;
    int solve(vector<vector<int>> & grid , int i ,int j ,int x,int k,vector<vector<vector<int>>> & dp){
        int n = grid.size();
        int m = grid[0].size();

        if(i >= n || j >= m){
            return 0;
        }
        x ^= grid[i][j];
        if(i == n-1 && j == m-1){
            if(x == k){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[i][j][x] != -1){
            return dp[i][j][x];
        }

        int right = solve(grid,i,j+1,x,k,dp);
        int down = solve(grid,i+1,j,x,k,dp);

        return dp[i][j][x] =((right + down) % mod ) ;
    }
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(16,-1)));
        int ans = solve(grid,0,0,0,k,dp);
        return ans ;
    }
};