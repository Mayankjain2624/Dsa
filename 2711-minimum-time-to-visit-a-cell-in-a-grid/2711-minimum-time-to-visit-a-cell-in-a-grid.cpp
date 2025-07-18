class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    bool isvalid(int x, int y, int n, int m) {
        if (x >= 0 && x < n && y >= 0 && y < m)
            return true;
        return false;
    }
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[1][0] > 1 && grid[0][1] > 1)
            return -1;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({grid[0][0], 0});
        vector<int> dist(n * m + m , 1e9);
        while (!pq.empty()) {
            int time = pq.top().first;
            int x = pq.top().second / m;
            int y = pq.top().second % m;
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (isvalid(nx, ny, n, m)) {
                    int nt;
                    if (time + 1 >= grid[nx][ny])
                        nt = time + 1;
                    else {
                        int r = grid[nx][ny] - 1 - time;
                        nt = ceil(r * 1.0 / 2) * 2 + time + 1;
                    }
                    if (nt < dist[nx * m + ny]) {
                        dist[nx * m + ny] = nt;
                        pq.push({nt, nx * m + ny});
                    }
                }
            }
        }
        return dist[n * m - 1];
    }
};