class Solution {
  public:
    void dfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < m &&
               !vis[nr][nc] &&
               grid[nr][nc] == 'O') {

                dfs(nr, nc, grid, vis);
            }
        }
    }

    vector<vector<char>> fill(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Left and Right boundaries
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 'O' && !vis[i][0])
                dfs(i, 0, grid, vis);

            if(grid[i][m - 1] == 'O' && !vis[i][m - 1])
                dfs(i, m - 1, grid, vis);
        }

        // Top and Bottom boundaries
        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 'O' && !vis[0][j])
                dfs(0, j, grid, vis);

            if(grid[n - 1][j] == 'O' && !vis[n - 1][j])
                dfs(n - 1, j, grid, vis);
        }

        // Convert unvisited O into X
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'O' && !vis[i][j])
                    grid[i][j] = 'X';
            }
        }

        return grid;
    }
};