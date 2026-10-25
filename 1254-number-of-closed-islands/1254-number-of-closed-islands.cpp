class Solution {
private:
    void dfs(vector<vector<int>> & grid ,int i ,int j){
        int n = grid.size();
        int m = grid[0].size();

        grid[i][j] = 1 ;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,+1,0,-1};

        for(int ind =0 ; ind<4 ; ind++){
            int nr = i + dx[ind];
            int nc = j + dy[ind];
            if(nr >=0 && nr < n && nc >=0 && nc < m && grid[nr][nc] == 0 ){
                dfs(grid,nr,nc);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0 ;
        for(int i =0 ; i<m ; i++){
            if(grid[0][i] == 0){
                dfs(grid,0,i);
            }
        }
        for(int i =0 ; i<n ; i++){
            if(grid[i][0] == 0){
                dfs(grid,i,0);
            }
        }
        for(int i =0 ; i<m ; i++){
            if(grid[n-1][i] == 0){
                dfs(grid,n-1,i);
            }
        }
        for(int i =0 ; i<n; i++){
            if(grid[i][m-1] == 0){
                dfs(grid,i,m-1);
            }
        }
        for(int i =0 ; i<n ; i++){ 
            for(int j =0 ; j<m ;j++){
                if(grid[i][j] == 0){
                    cnt++;
                    dfs(grid,i,j);

                }
            }
            
        }
        return cnt ;
    }
};