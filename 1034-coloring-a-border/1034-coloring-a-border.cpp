class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis,
             int i, int j, int int_col, int color) {
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int ind = 0; ind < 4; ind++) {
            int nr = i + dx[ind];
            int nc = j + dy[ind];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                grid[nr][nc] == int_col && !vis[nr][nc]) {
                dfs(grid, vis, nr, nc, int_col, color);
            }
        }
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid,
                                    int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();

        int int_col = grid[row][col];

        if (int_col == color) return grid;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> border(n, vector<int>(m, 0));

        dfs(grid, vis, row, col, int_col, color);

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j]) {
                    int sides = 0;

                    for (int k = 0; k < 4; k++) {
                        int nr = i + dx[k];
                        int nc = j + dy[k];

                        if (nr < 0 || nr >= n || nc < 0 || nc >= m ||
                            grid[nr][nc] != int_col) {
                            sides++;
                        }
                    }

                    if (sides > 0) {
                        border[i][j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (border[i][j]) {
                    grid[i][j] = color;
                }
            }
        }

        return grid;
    }
};