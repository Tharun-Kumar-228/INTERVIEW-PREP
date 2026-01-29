class Solution {
public:
    queue<pair<int,int>> q;
    int count = 0;
    int min = 0;

    int orangesRotting(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    count++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        return bfs(grid);
    }

    int bfs(vector<vector<int>>& grid) {
        if (count == 0) return 0;

        while (!q.empty() && count > 0) {
            int n = q.size();

            while (n--) {
                pair<int,int> p = q.front();
                q.pop();

                int r = p.first;
                int c = p.second;

                if (r + 1 < grid.size() && grid[r+1][c] == 1) {
                    grid[r+1][c] = 2;
                    q.push({r+1, c});
                    count--;
                }
                if (r - 1 >= 0 && grid[r-1][c] == 1) {
                    grid[r-1][c] = 2;
                    q.push({r-1, c});
                    count--;
                }
                if (c - 1 >= 0 && grid[r][c-1] == 1) {
                    grid[r][c-1] = 2;
                    q.push({r, c-1});
                    count--;
                }
                if (c + 1 < grid[r].size() && grid[r][c+1] == 1) {
                    grid[r][c+1] = 2;
                    q.push({r, c+1});
                    count--;
                }
            }
            min++;
        }

        return (count == 0) ? min : -1;
    }
};
