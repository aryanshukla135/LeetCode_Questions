class Solution {
private:
   int bfs(int row,int col , vector<vector<int>>&vis,vector<vector<int>>& grid,int cnt){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
       int delRow[] = {-1, 0, 1, 0};
       int delCol[] = {0, 1, 0, -1};
       int n = grid.size();
       int m = grid[0].size();


        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            cnt++;
            for(int i = 0; i < 4; i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                  if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
            }
        }
        return cnt ;

   }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
         int m = grid[0].size();

         vector<vector<int>>vis(n,vector<int>(m,0));
        
         int maxarea = INT_MIN;
         for(int i =0 ;i< n ; i++){
            for(int j =0 ;j<m ; j++){
                if(grid[i][j] != 0 && !vis[i][j]){
                    int a=bfs(i,j,vis,grid,0);
                   maxarea = max(maxarea,a);
                }
            }
         }
         if(maxarea == INT_MIN){
            return 0 ;
         }
         return maxarea ; 
    }
};


/*

void bfs(int row,int col , vector<vector<int>>&vis,vector<vector<char>>& grid){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
       int delRow[] = {-1, 0, 1, 0};
       int delCol[] = {0, 1, 0, -1};
       int n = grid.size();
       int m = grid[0].size();


        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

             for(int i = 0; i < 4; i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                  if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
            }
        }

   }
public:
    int numIslands(vector<vector<char>>& grid) {
         int n = grid.size();
         int m = grid[0].size();

         vector<vector<int>>vis(n,vector<int>(m,0));
         int cnt =0;
         for(int i =0 ;i< n ; i++){
            for(int j =0 ;j<m ; j++){
                if(grid[i][j] != '0' && !vis[i][j]){
                   cnt++;
                   bfs(i,j,vis,grid);
                }
            }
         }
         return cnt ; 
    }
};

*/