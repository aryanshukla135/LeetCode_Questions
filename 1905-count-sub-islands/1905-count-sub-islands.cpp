class Solution {
private:
    bool dfs(int row ,int col , vector<vector<int>>& vis ,vector<vector<int>>& grid1, vector<vector<int>>& grid2,int delrow[] ,int delcol[],int m,int n){
       
        vis[row][col] = 1;

        bool flag = true;

        if(grid1[row][col] == 0)
            flag = false;

        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&
               vis[nrow][ncol]==0 && grid2[nrow][ncol]==1){

                flag &= dfs(nrow,ncol,vis,grid1,grid2,
                            delrow,delcol,m,n);
            }
        }

        return flag;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();

        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
    
        vector<vector<int>> vis(m ,vector<int>(n,0));
        int cnt =0;
        bool flag = true;
        for(int i =0 ; i<m ; i++){
            for(int j =0 ; j< n ; j++){
                   if(grid2[i][j]==1 && vis[i][j]==0 && grid1[i][j]==1){
                      if(dfs(i,j,vis,grid1,grid2,delrow,delcol,m,n)){
                         cnt++;
                      }
                   }
            }
        }
        return cnt ;
    }
};