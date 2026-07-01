class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};

        vector<vector<int>> mat(n,vector<int>(n,0));
       
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q ;
        for(int i =0 ; i< n ; i++){
            for(int j =0 ; j<n ; j++ ){
                if(grid[i][j] == 1 && vis[i][j] ==0){
                    vis[i][j] = 1;
                    q.push({0,{i,j}});
                }
            }
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int step = it.first;
            int row = it.second.first;
            int col = it.second.second;

            mat[row][col] = step;

            for(int i =0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol] == 0){
                      vis[nrow][ncol] = 1 ;
                      q.push({step+1,{nrow,ncol}});
                }
            }
        }
        
       // {safefact,{row,col}}
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> dist(n,vector<int>(n,INT_MIN));

        pq.push({mat[0][0],{0,0}});
        dist[0][0] = mat[0][0];


        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int safefactor = it.first;
            int row = it.second.first ;
            int col = it.second.second;
            
            if(row == n-1 && col == n-1){
                return safefactor;
            }
           
            for(int i =0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];


                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n ){
                       int newsafe = min(safefactor,mat[nrow][ncol]);
                       if(newsafe > dist[nrow][ncol]){
                           dist[nrow][ncol] = newsafe ;
                           pq.push({newsafe,{nrow,ncol}});
                       }  
                }
            }
        }

     return dist[n-1][n-1];

    }
};