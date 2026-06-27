class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(n,vector<int>(n,1e9));
        if(grid[0][0] != 0){
            return -1;
        }

        mat[0][0] = 0;
        int delrow[] = {+1,-1,0,+1,-1,+1,0,-1};
        int delcol[] = {0,+1,+1,+1,0,-1,-1,-1};

          //{dis,{row,col}}
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq ;
          pq.push({1,{0,0}}) ;

        while(!pq.empty()){
            int dist = pq.top().first ;
            int row = pq.top().second.first ;
            int col = pq.top().second.second ;
            pq.pop();
            if(row == n-1 && col == n-1){
                return dist;
            }

            for(int i =0 ; i<8 ; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                int ndist = 1 ;

                if(nrow>=0 && nrow<n && ncol >=0 && ncol<n && grid[nrow][ncol]==0){
                    if(dist + ndist < mat[nrow][ncol]){
                        mat[nrow][ncol] = dist + ndist ;
                        pq.push({dist+ndist ,{nrow,ncol}});
                    }
                }
            }
        }  
        if(mat[n-1][n-1] == 1e9){
            return -1;
        }
        return mat[n-1][n-1];
    }
};