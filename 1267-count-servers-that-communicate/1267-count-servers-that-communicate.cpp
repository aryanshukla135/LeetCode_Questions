class Solution {
private:
    void dfs(vector<vector<int>> & grid , vector<vector<bool>> & vis , int i , int j,int & cnt ){
         int n = grid.size();
         int m = grid[0].size();

         if(i < 0 || i >= n || j < 0 || j >= m){
            return ;
         }
         vis[i][j] = 1 ;
         cnt++;
        
         // col
         for(int ind = 0 ; ind < m ; ind++){
            if(grid[i][ind] == 1 && vis[i][ind] == 0){
                dfs(grid,vis,i,ind,cnt);
            }
         }
         // row
         for(int ind = 0 ; ind < n ; ind++){
            if(grid[ind][j] == 1 && vis[ind][j] == 0){
                dfs(grid,vis,ind,j,cnt);
            }
         }
    }
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,0));
        int totalCnt = 0 ;
        for(int i =0 ; i<n ; i++){
            for(int j =0 ; j < m ; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int cnt = 0;
                    dfs(grid,vis,i,j,cnt);
                    if(cnt > 1 ){
                        totalCnt += cnt;
                    }
                }
            }
        }
        return totalCnt ;
    }
};