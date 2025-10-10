class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
         int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int n1=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(board[i][j] == 1)
                n1++;
                if ((i == 0 || j == 0 || i == n - 1 || j == m- 1) &&
                    board[i][j] ==1) {
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
                            if (!vis[nr][nc] && board[nr][nc] == 1) {
                                vis[nr][nc] = 1;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        int ans=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // cout<<vis[i][j]<<" ";
                if (vis[i][j] == 1)
                ans++;
                    // board[i][j] = 'X';
                // else
                //     board[i][j] = 'O';
            }
            // cout<<endl;
        }
        return n1-ans;
    }
};