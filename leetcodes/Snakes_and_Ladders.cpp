#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> linear;

        // Convert 2D board into linear array
        destructure(board, linear);

        int total = n * n;
        vector<bool> visited(total, false);
        queue<pair<int,int>> q; // {cell index, moves}

        // Start from cell 0
        q.push({0, 0});
        visited[0] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();

            // Reached the last cell
            if (curr == total - 1) 
                return moves;

            // Try all dice rolls 1..6
            for (int dice = 1; dice <= 6 && curr + dice < total; dice++) {
                int next = curr + dice;

                // Jump to ladder or snake if present
                if (linear[next] != -1)
                    next = linear[next] - 1;

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        // If no path found
        return -1;
    }

    void destructure(vector<vector<int>>& board, vector<int>& linear) {
        int n = board.size();
        bool leftToRight = true;

        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++)
                    linear.push_back(board[i][j]);
            } else {
                for (int j = n - 1; j >= 0; j--)
                    linear.push_back(board[i][j]);
            }
            leftToRight = !leftToRight;
        }
    }
};
