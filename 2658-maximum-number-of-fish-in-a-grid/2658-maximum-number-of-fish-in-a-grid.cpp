class Solution {
private:
    int dfs(int row ,int col , vector<vector<int>>& grid , vector<vector<int>> & vis, int delrow[] ,int delcol[],int n ,int m ){
        vis[row][col] =1 ;
         int sum = grid[row][col];
        for(int i =0 ; i<4 ; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] >0 && vis[nrow][ncol] == 0){
              sum += dfs(nrow,ncol,grid,vis,delrow,delcol,n,m);
            }
        }
        return sum ;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxarea =0;
        vector<vector<int>> vis(n,vector<int>(m,0));

        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};

        for(int i =0 ; i< n ; i++){
            for(int j =0 ; j<m ; j++){
                if(grid[i][j] > 0 && vis[i][j] ==0){
        
                    int a= dfs(i,j,grid,vis,delrow,delcol,n,m);
                    maxarea = max(maxarea,a);
                    
                }
            }
        }
        return maxarea;
    }
};