class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        int delrow[] = {+1,0,-1,0};
        int delcol[] = {0,+1,0,-1};
        vector<vector<int>> dist(n , vector<int>(m,1e9));
        //{diff,{row,col}}
        priority_queue<pair<int,pair<int,int>>,vector<pair<int ,
        pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq ;

        pq.push({0,{0,0}});
        dist[0][0] = 0 ;

        while(!pq.empty()){
            int diff = pq.top().first;
            int row = pq.top().second.first ;
            int col = pq.top().second.second;

            pq.pop();

            for(int i =0; i< 4 ; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
              

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int ndiff = abs(heights[nrow][ncol]-heights[row][col]);
                    if(max(ndiff,diff)<dist[nrow][ncol]){
                        dist[nrow][ncol] = max(ndiff,diff);
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }

        }
        return dist[n-1][m-1];
    }
};