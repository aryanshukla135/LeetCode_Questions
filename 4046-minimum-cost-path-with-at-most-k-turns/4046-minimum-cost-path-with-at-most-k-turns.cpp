class Solution {
private:
int f(vector<vector<int>>& grid, int i, int j, int k, int prev, int turn,vector<vector<vector<vector<int>>>>& dp) {

        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size()) {
            return 1e9;
        }
        if (turn > k) {
            return 1e9;
        }
        if (i == 0 && j == 0) {
            return grid[i][j];
        }
        if(dp[i][j][prev][turn] != -1) return dp[i][j][prev][turn];
        int newTurn = turn;
        if (prev != 0 && prev != 1) {
            newTurn++;
        }
        int up = grid[i][j] +
                 f(grid, i - 1, j, k, 1, newTurn,dp);

        newTurn = turn;
        if (prev != 0 && prev != 2) {
            newTurn++;
        }
        int down = grid[i][j] +
                   f(grid, i + 1, j, k, 2, newTurn,dp);

        newTurn = turn;
        if (prev != 0 && prev != 3) {
            newTurn++;
        }
        int left = grid[i][j] +
                   f(grid, i, j - 1, k, 3, newTurn,dp);

        newTurn = turn;
        if (prev != 0 && prev != 4) {
            newTurn++;
        }
        int right = grid[i][j] +
                    f(grid, i, j + 1, k, 4, newTurn,dp);

        return dp[i][j][prev][turn] = min({up, down, left, right});
    }
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

    vector<vector<vector<vector<int>>>> dp( n,vector<vector<vector<int>>>( m,
    vector<vector<int>>(6,vector<int>(k + 1, -1))));

        int ans = f(grid,n-1,m-1,k,0,0,dp);
        if(ans >=1e9){
            return -1;
        }

        return ans;

    //     int delRow[] = {-1, 1, 0, 0};
    //     int delCol[] = {0, 0, -1, 1};

    //     vector<vector<int>> dist(n,vector<int>(m,1e9));
    //     // dist,k , i , j 
    //     priority_queue<
    //     pair<int, pair<int, pair<int, int>>>,
    //     vector<pair<int, pair<int, pair<int, int>>>>,
    //     greater<pair<int, pair<int, pair<int, int>>>>> pq;

    //     pq.push({grid[0][0],{0,{0,0}}});
    //     dist[0][0] = grid[0][0];

    //     while(!pq.empty()){
    //         auto it = pq.top();
    //         pq.pop();

    //         int dis = it.first;
    //         int k = it.second.first;
    //         int i = it.second.second.first;
    //         int j = it.second.second.second;

    //         if(i == n-1 && j == m-1){
    //             return grid[n-1][m-1];
    //         }
    //         if(k<=0){
    //             continue;
    //         }

    //         for(int l = 0 ; l<4 ; l++){
    //             int nr = delRow[l] + i;
    //             int nc = delCol[l] + j;

    //             if(nr>=0 && nr<n && nc>=0 && nc<m){
    //                 if(dis + grid[nr][nc] < dist[nr][nc]){
    //                     pq.push({dis + grid[nr][nc],{k-1,{nr,nc}}});
    //                 }
    //             }
    //         }
    //     }
    // return -1;
        
    }
};