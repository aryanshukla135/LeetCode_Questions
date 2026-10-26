class Solution {
private:
    void dfs(vector<vector<int>> & grid , int i , int j , long long & sum){
        int n = grid.size();
        int m = grid[0].size();
        sum += grid[i][j];
        grid[i][j] = 0;
        int dx[] = {-1,0,+1,0};
        int dy[] = {0,+1,0,-1};

        for(int ind = 0; ind < 4; ind++ ){
            int nr = i + dx[ind];
            int nc = j + dy[ind];

            if(nr >=0 && nr < n && nc>=0 && nc <m && grid[nr][nc] != 0){
                dfs(grid,nr,nc,sum);
            }
        }
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt =0; 
        for(int i =0 ; i<n ;i++){
            for(int j =0 ; j<m ; j++){
                if(grid[i][j] !=0){
                    long long sum =0 ;
                    dfs(grid,i,j,sum);
                    if(sum % k == 0){
                        cnt++;
                    }
                }
            }
        }
        return cnt ;
    }
};