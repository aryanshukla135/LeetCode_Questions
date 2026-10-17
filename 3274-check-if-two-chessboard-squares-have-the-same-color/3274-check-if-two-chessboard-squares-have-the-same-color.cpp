class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
         vector<vector<int>> grid(8,vector<int>(8,0));
         bool flip = false ;
         for(int i =0 ; i<8 ; i++){
            for(int j = 0 ;j < 8 ; j++){
                if(!flip){
                    grid[i][j] = 1 ;
                }
                flip = !flip ;
            }
            flip = !flip;
         }
         
         int r1 = coordinate1[0] - 'a';
         int c1 = coordinate1[1] - '1';
         int r2 = coordinate2[0] - 'a';
         int c2 = coordinate2[1] - '1';
         
      return grid[r1][c1] == grid[r2][c2] ;
    }
};