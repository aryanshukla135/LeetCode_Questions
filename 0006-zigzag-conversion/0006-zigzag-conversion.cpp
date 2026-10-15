class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        vector<vector<char>> grid(n,vector<char>(n,' '));
        int col = 0 ;
        for(int i= 0; i<n ; ){
            // for  numrowws 
            for(int row =0 ; i < n && row<numRows ; row++){
                grid[row][col] = s[i];
                i++;
            }
            col++;
            // for other ( numrows - 2 )
            int m = numRows - 2 ;
            int l = numRows - 2 ;
            for( ; l > 0 && i < n ; l--){
                grid[l][col++] = s[i++];
            } 
        }
    string ans ="";
    for(int i =0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            if(grid[i][j] != ' '){
                ans += grid[i][j];
            }  
        }
    }




  
     return ans;
    }
};