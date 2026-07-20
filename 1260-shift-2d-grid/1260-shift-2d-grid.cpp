class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
         int n = grid.size();
         int m = grid[0].size();

         vector<vector<int>> result(n,vector<int>(m,0)) ;
         int cnt =-1 ;
         int x = -1 ;
         int y = -1; 
         int total = m *n ;
         k = k % total ;
         cout<<k<<endl ;

         for(int i = 0 ; i<n ; i++){
            for(int j =0 ;j<m ; j++){
                cnt++;

                if(cnt == k){
                    x = i ;
                    y = j ;
                    break ;
                }
            }
         }
         for(int i =0 ; i<n ; i++){
            for(int j =0 ; j<m ; j++){
                result[x][y] = grid[i][j];               
                if(y == m-1){
                    y = 0;
                    if (x == n - 1)
                        x = 0;
                    else
                       x++;
                }else{
                    y++;
                }
                
 
            }
         }

         return result ;
         
    }
};