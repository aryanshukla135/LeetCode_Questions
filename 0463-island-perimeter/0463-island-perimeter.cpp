class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited,
             int i, int j, int& ans) {
        visited[i][j] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int ind = 0; ind < 4; ind++) {
            int nr = i + dx[ind];
            int nc = j + dy[ind];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                ans++;
            }
            else if (grid[nr][nc] == 0) {
                ans++;
            }
            else if (!visited[nr][nc]) {
                dfs(grid, visited, nr, nc, ans);
            }
        }
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    dfs(grid, visited, i, j, ans);
                }
            }
        }

        return ans;
    }
};