class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(n == 1 && m == 1) return 0;
        if((n == 1 || grid[1][0] > 1) &&
           (m == 1 || grid[0][1] > 1)) {
            return -1;
        }
        
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        priority_queue<P,vector<P>,greater<P>> pq ;
        pq.push({0,{0,0}});
        dist[0][0] = 0 ;

        int dx[] = {-1,0,+1,0};
        int dy[] = {0,+1,0,-1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i = 0 ; i<4 ; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr >=0 && nr < n && nc >=0 && nc < m){

                    int ntime = time + 1;

                    if(ntime < grid[nr][nc]) {
                        ntime = grid[nr][nc] +
                                (grid[nr][nc] - ntime) % 2;
                    }
            
                    if(dist[nr][nc] > ntime){
                        dist[nr][nc] = ntime;
                        pq.push({ntime,{nr,nc}});
                    }
                }
            }
        }

    if(dist[n-1][m-1] != INT_MAX){
        return dist[n-1][m-1];
    }
    return -1;

    }
};