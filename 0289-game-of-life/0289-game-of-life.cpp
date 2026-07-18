class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> grid(n,vector<int>(m,0));

        int delrow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delcol[] = {-1,  0,  1,-1, 1,-1, 0, 1};

        for(int i =0 ; i<n ; i++){
            for(int j =0 ; j<m ; j++){
                int lives = 0;

                for(int k =0 ; k< 8 ; k++){
                    int nrow = i+delrow[k];
                    int ncol = j+delcol[k];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                        if(board[nrow][ncol] == 1){
                            lives++;
                        }
                    }
            }
             if(lives < 2){
                grid[i][j] = 0;
             }else if( board[i][j] == 1 && (lives == 2 || lives ==3)){
                grid[i][j] = 1 ;
             }else if(lives > 3){
                grid[i][j] = 0 ;
             }else if(board[i][j] == 0 &&  lives == 3){
                grid[i][j] = 1 ;
             }
            }
        }
        for(int i =0 ; i<n ; i++){
            for(int j = 0 ; j <m ; j++){
                board[i][j] = grid[i][j];
            }
        }
    }
};