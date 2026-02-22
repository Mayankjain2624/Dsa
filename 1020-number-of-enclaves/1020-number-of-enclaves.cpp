class Solution {
public:
    bool isValid(int x, int y, int n, int m) {
        if (x >= 0 && x < n && y >= 0 && y < m)
            return true;
        return false;
    }
    vector<int> di = {1, 0, -1, 0};
    vector<int> dj = {0, 1, 0, -1};
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + di[i];
                int ny = y + dj[i];
                if(isValid(nx,ny,n,m) && grid[nx][ny]==1){
                    grid[nx][ny]=0;
                    q.push({nx,ny});
                }
            }
        }
        int cnt=0;
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]==1)
                  cnt++;
            }
        }
        return cnt;
    }
};