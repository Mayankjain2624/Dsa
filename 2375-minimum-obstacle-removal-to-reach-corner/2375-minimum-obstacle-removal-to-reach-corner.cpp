class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    bool isvalid(int x, int y, int n, int m) {
        if (x >= 0 && x < n && y >= 0 && y < m)
            return true;
        return false;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        pq.push({grid[0][0], 0});
        dist[0][0] = grid[0][0] ? 1 : 0;
        while (!pq.empty()) {
            auto top = pq.top();
            int cost = top.first;
            int x = top.second / m;
            int y = top.second % m;
            pq.pop();
            if (x == n - 1 && y == m - 1)
                return cost;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (isvalid(nx, ny, n, m) && grid[nx][ny] == 1 &&
                    dist[nx][ny] > cost + 1) {
                    dist[nx][ny] = cost + 1;
                    pq.push({cost + 1, nx * m + ny});
                } else if (isvalid(nx, ny, n, m) && grid[nx][ny] == 0 &&
                           dist[nx][ny] > cost) {
                    dist[nx][ny] = cost;
                    pq.push({cost, nx * m + ny});
                }
            }
        }
        return -1;
    }
};