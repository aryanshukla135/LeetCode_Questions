class Solution {
private:
    int f(vector<vector<int>> & grid, int i , int j1,int j2,vector<vector<vector<int>>> &dp ){
        int n = grid.size();
        int m = grid[0].size();
        if(j1<0 || j1 >=m || j2 < 0 || j2 >=m){
            return -1e9;
        }
        if(i == n-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e9;
        for(int ind = -1 ; ind<=1 ; ind++){
            for(int j = -1 ; j<=1 ; j++){
                int val = 0;
                if(j1 == j2){
                   val = grid[i][j1];
                }else{
                   val = grid[i][j1] + grid[i][j2];
                }
                int ans = val + f(grid ,i +1 , j1+ ind , j2+j,dp);
                maxi = max(maxi,ans);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m, -1)));
        return f(grid,0,0,m-1,dp);
    }
};