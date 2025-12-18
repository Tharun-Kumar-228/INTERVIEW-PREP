// class Solution {
// public:
//     vector<vector<int>> findFarmland(vector<vector<int>>& land) {
//         vector<vector<int>> ans;
//         int n = land.size(), m = land[0].size();
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (land[i][j] == 1) {
//                     int r = i, c = j;
//                     while (c + 1 < m && land[i][c + 1] == 1)
//                         c++;
//                     while (r + 1 < n && land[r + 1][j] == 1)
//                         r++;
//                     for (int x = i; x <= r; x++) {
//                         for (int y = j; y <= c; y++) {
//                             land[x][y] = 0;
//                         }
//                     }
//                     ans.push_back({i, j, r, c});
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxR, maxC;

    void dfs(vector<vector<int>>& land, int r, int c) {
        int n = land.size(), m = land[0].size();
        if (r < 0 || c < 0 || r >= n || c >= m || land[r][c] == 0)
            return;
        land[r][c] = 0;     
        maxR = max(maxR, r);
        maxC = max(maxC, c);
        dfs(land, r + 1, c);
        dfs(land, r, c + 1);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;

        for (int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land[0].size(); j++) {
                if (land[i][j] == 1) {
                    maxR = i;
                    maxC = j;

                    dfs(land, i, j);

                    ans.push_back({i, j, maxR, maxC});
                }
            }
        }
        return ans;
    }
};
