class Solution {
private:
    int f(vector<vector<int>> & grid , vector<vector<int>> & cost , int i , int j , vector<vector<int>> & dp){
        int n = grid.size();
        int m = grid[0].size();

        if(i == n-1){
            return grid[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        for(int k =0 ; k<m ; k++){
            mini = min(mini,grid[i][j] + cost[grid[i][j]][k] + f(grid,cost,i+1,k,dp)); 
        }

        return dp[i][j] = mini;
    }
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int mini = INT_MAX;

        for(int i =0 ; i<m ; i++){
            mini = min(mini,f(grid,moveCost,0,i,dp));
        }
        return mini ;
    }
};