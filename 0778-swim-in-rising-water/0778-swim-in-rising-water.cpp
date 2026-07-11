class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
         int n = grid.size();
         int delrow[] = {-1,0,+1,0};
         int delcol[] = {0,+1,0,-1};

         vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq ;

         pq.push({grid[0][0],{0,0}});
         dist[0][0] = grid[0][0] ;

         while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int row = it.second.first;
            int col = it.second.second ;

            for(int i =0 ; i< 4 ; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n){
                    int timediff = grid[nrow][ncol] - time ;

                    if(timediff > 0){
                        int reqtime = time + timediff;
                        if(reqtime < dist[nrow][ncol]){
                            dist[nrow][ncol] = reqtime ;
                            pq.push({reqtime,{nrow,ncol}});
                        }
                    }else{
                        if(time < dist[nrow][ncol]){
                            dist[nrow][ncol] = time ;
                            pq.push({time,{nrow,ncol}});
                        }
                    }
                }
            }

         }
         
        return dist[n-1][n-1];
     
    }
};