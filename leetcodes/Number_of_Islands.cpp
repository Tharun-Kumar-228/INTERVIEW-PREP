class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) parent[b] = a;
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

       
        parent.resize(rows * cols + 1);
        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;

        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    int up = (i > 0) ? visited[i - 1][j] : 0;
                    int left = (j > 0) ? visited[i][j - 1] : 0;

                    if (up == 0 && left == 0) {
                        
                        count++;
                        visited[i][j] = count;
                    }
                    else if (up != 0 && left != 0) {
                      
                        visited[i][j] = min(up, left);
                        if (up != left) {
                            unite(up, left);  
                        }
                    }
                    else {
                        
                        visited[i][j] = max(up, left);
                    }
                }
            }
        }

      
        unordered_set<int> islands;
        for (int i = 1; i <= count; i++) {
            islands.insert(find(i));
        }

        return islands.size();
    }
};
