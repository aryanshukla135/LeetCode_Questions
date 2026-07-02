class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
         int n = grid.size();
         int m = grid[0].size();

         vector<vector<int>> dist(n,vector<int>(m,INT_MIN));

          int delrow[] = {-1,0,+1,0};
          int delcol[] = {0,+1,0,-1};

          queue<pair<int,pair<int,int>>>pq;
        
          if(grid[0][0] ==1){
             health--;
          }
        
          pq.push({health,{0,0}});
          dist[0][0] = health;

          while(!pq.empty()){
             int h = pq.front().first;
             int row = pq.front().second.first;
             int col = pq.front().second.second;

             pq.pop();
             if(row == n-1 && col==m-1 && h >=1){
                return true;
             }

             for(int i =0 ; i<4 ; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                int newhealth = h;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                      if(grid[nrow][ncol] == 1){
                         newhealth--;
                      }
                      
                      if(newhealth>0){
                        if(newhealth > dist[nrow][ncol]){
                             pq.push({newhealth,{nrow,ncol}});
                             dist[nrow][ncol] = newhealth;
                        } 
                      }
                }
             }
          }
          
          return false;
    }
};