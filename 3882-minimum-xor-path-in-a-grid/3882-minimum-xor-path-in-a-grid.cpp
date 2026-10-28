class Solution {
private:
    int solve(vector<vector<int>> & grid , int i , int j,int temp,vector<vector<vector<int>>> & dp ){
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m){
            return INT_MAX;
        }
        temp ^= grid[i][j];
        if( i == n-1 && j == m-1){
            return temp;
        }
        if(dp[i][j][temp] != -1){
            return dp[i][j][temp];
        }

        int right =  solve(grid,i,j+1,temp,dp);
        int down = solve(grid,i+1,j,temp,dp);

        return dp[i][j][temp] = min(right,down);
    }
    
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(1024,-1)));
        int ans =  solve(grid,0,0,0,dp);
        return ans;
    }
};