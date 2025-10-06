class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    bool isvalid(int x, int y, int n, int m) {
        if (x >= 0 && x < n && y >= 0 && y < m)
            return true;
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n, 1e9));
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        ans[0][0] = grid[0][0];
        while (!pq.empty()) {

            int x = pq.top().first;
            int y = pq.top().second;
            pq.pop();
            for (int di = 0; di < 4; di++) {
                int nx = x + dx[di];
                int ny = y + dy[di];
                if (isvalid(nx, ny, n, n)) {
                    if (ans[nx][ny] > max(ans[x][y], grid[nx][ny])) {
                        ans[nx][ny] = max(ans[x][y], grid[nx][ny]);
                        pq.push({nx, ny});
                    }
                }
            }
        }
        return ans[n - 1][n - 1];
    }
};