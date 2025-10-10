class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m- 1) &&
                    board[i][j] == 'O') {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 || dj == 0) {
                        int nr = r + di;
                        int nc = c + dj;
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                            if (!vis[nr][nc] && board[nr][nc] == 'O') {
                                vis[nr][nc] = 1;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0)
                    board[i][j] = 'X';
                else
                    board[i][j] = 'O';
            }
        }
        // return board;
    }
};