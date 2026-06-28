class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;

        int cnt = 0;
        if(grid[0][0]==1){
            cnt =1 ;
        }
        q.push({cnt,{0,0}});
        dist[0][0]=cnt;
        
        while(!q.empty()){
            int count = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
           
            q.pop();

            for(int i =0 ; i<4 ; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                int cnt = count;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    if(grid[nrow][ncol]==1){
                        cnt++;
                    }
                    if(cnt<dist[nrow][ncol]){
                        dist[nrow][ncol] = cnt ;
                        q.push({cnt,{nrow,ncol}});
                    }
                }
            }

        }
        return dist[n-1][m-1];
    }
};