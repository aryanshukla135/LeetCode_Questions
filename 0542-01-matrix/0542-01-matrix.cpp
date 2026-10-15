class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
   
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};

        queue<pair<int,pair<int,int>>> q ;
        for(int i =0; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1 ;
                    q.push({0,{i,j}});
                }
            }
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int step = it.first;
            int row = it.second.first;
            int col = it.second.second ;
            mat[row][col] = step;

            for(int i =0 ; i<4 ; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0){
                     vis[nrow][ncol] = 1 ;
                     q.push({step + 1 ,{nrow,ncol}});
                }
            }
        }
        return mat ;
    }
};