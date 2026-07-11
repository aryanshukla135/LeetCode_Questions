class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
         int n = grid.size();
         int m = grid[0].size();

         int widthfirst= INT_MAX ;
         int widthlast = INT_MIN;
         int heightfirst = INT_MAX;
         int heightlast = INT_MIN;
         for(int i = 0 ; i< n ; i++){
            for(int j =0 ; j<m ; j++){
                if(grid[i][j] ==1){
                    widthfirst = min(widthfirst,j);
                    widthlast = max(widthlast,j);
                    heightfirst = min(heightfirst,i);
                    heightlast = max(heightlast,i);
                }
            }
         }
         
         int width = widthlast - widthfirst + 1 ;
         int height = heightlast - heightfirst + 1 ;

         return width * height ;
    }
};