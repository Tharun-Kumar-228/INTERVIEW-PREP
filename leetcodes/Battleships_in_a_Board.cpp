class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return 0;
        int cols = board[0].size();

        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'X') {
                    dfs(board, i, j);
                    count++; 
                }
            }
        }
        return count;
    }

    int dfs(vector<vector<char>>& board, int r, int c) {
        int rows = board.size();
        int cols = board[0].size();

        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'X')
            return 0;

        board[r][c] = '.';

        int size = 1; 
        size += dfs(board, r + 1, c);
        size += dfs(board, r - 1, c);
        size += dfs(board, r, c + 1);
        size += dfs(board, r, c - 1);

        return size;
    }
};
