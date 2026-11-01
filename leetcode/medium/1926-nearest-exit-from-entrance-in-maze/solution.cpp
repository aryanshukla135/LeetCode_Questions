class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        int r = entrance[0];
        int c = entrance[1];

        int dr[] = {-1,0,+1,0};
        int dc[] = {0,+1,0,-1};

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q ;

        q.push({0,{r,c}});
        vis[r][c] = 1 ;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int step = it.first ;
            int row = it.second.first;
            int col = it.second.second;

            if ((row == 0 || row == n-1 || col == 0 || col == m-1) && !(row == r && col == c)) {
                 return step;
            }
            for(int i =0 ; i<4 ; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr >=0 && nr < n && nc >=0 && nc < m && vis[nr][nc] != 1 && maze[nr][nc] == '.'){
                    vis[nr][nc] = 1 ;
                    q.push({step + 1 ,{nr,nc}});
                }
            }

        }

    return -1;
    }
};