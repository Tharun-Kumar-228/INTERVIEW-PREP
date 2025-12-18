class Solution {
public:
    int n, m;

    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c) {
        if (r < 0 || c < 0 || r >= n || c >= m || grid2[r][c] == 0)
            return true;


        grid2[r][c] = 0;

        bool isSub = (grid1[r][c] == 1);

        bool up    = dfs(grid1, grid2, r - 1, c);
        bool down  = dfs(grid1, grid2, r + 1, c);
        bool left  = dfs(grid1, grid2, r, c - 1);
        bool right = dfs(grid1, grid2, r, c + 1);

        return isSub && up && down && left && right;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid2.size();
        m = grid2[0].size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1) {
                    if (dfs(grid1, grid2, i, j))
                        count++;
                }
            }
        }
        return count;
    }
};
