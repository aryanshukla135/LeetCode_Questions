class Solution {
private:
    void dfs(vector<vector<char>>& board,  vector<vector<int>>& vis,int delrow[],int delcol[] , int n ,int m ,int row ,int col ){
        vis[row][col] =1; 

        for(int i =0; i<4 ; i++ ){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow< n && ncol>=0 && ncol<m && board[nrow][ncol] == 'X' && vis[nrow][ncol] == 0){
                dfs(board,vis,delrow,delcol,n,m,nrow,ncol);
            }
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};

        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt =0;
        for(int i = 0; i<n ; i++){
            for(int j =0 ; j<m ; j++){
                if(board[i][j]=='X' && vis[i][j] == 0){
                    cnt++;
                    dfs(board,vis,delrow,delcol, n , m ,i,j);
                }
            }
        }

        return cnt ;
    }
};
