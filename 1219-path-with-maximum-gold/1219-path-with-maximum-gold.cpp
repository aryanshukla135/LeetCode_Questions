class Solution {
private:
    int solve(vector<vector<int>> & grid,vector<vector<int>> & vis , int i , int j,int delrow[],int delcol[] ){
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;
        int maxi = 0;
        for(int l =0 ; l<4 ; l++){
            int nr = i + delrow[l] ;
            int nc = j + delcol[l] ;

            if(nr >=0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] !=1 && grid[nr][nc] != 0){
              maxi = max(maxi,grid[nr][nc] + solve(grid,vis,nr,nc,delrow,delcol));
            
            }
        }
        vis[i][j] = 0 ;
        return maxi ;
    } 
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {0,0,-1,1};
        int delcol[] = {-1,1,0,0};
        int maxi = 0 ;
        for(int i =0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
               vector<vector<int>> vis(n,vector<int>(m,0));
               maxi = max(maxi,grid[i][j] + solve(grid,vis,i,j,delrow,delcol));
            }
        }
        return maxi; 
    }
};