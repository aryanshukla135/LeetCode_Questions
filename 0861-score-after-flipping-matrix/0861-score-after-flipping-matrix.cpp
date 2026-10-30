class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> col ;
      
        for(int i =0 ; i<n ;i++){
            if(grid[i][0] == 0){
               for(int j = 0 ; j<m ; j++){
                  grid[i][j] = !grid[i][j];
               }  
            }
        }
        for(int i =0 ; i<m ; i++){
            int zero = 0;
            int one = 0;
            for(int j = 0 ; j<n ; j++){
                if(grid[j][i] == 0){
                    zero++;
                }else{
                    one++;
                }
            }
            if(zero > one){
               for(int j = 0 ; j<n ; j++){
                  grid[j][i] = !grid[j][i];
               }  
            }
        }

        int ans = 0;
        for(int i =0 ; i<n; i++){
            int ind = 0 ;
            int temp  = 0 ;
            for(int j = m - 1 ; j>=0 ; j--){
                if(grid[i][j] == 1){
                    temp += pow(2,ind);
                }
                ind++;
            }
            ans += temp ;
        }


       for(int i =0 ; i<n ;i++){
        for(int j =0 ; j<m ; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
       }
       return ans;

    }
};