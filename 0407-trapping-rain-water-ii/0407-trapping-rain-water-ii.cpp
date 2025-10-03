class Solution {
public:
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        if (heightMap.size() < 3 || heightMap[0].size() < 3) {
            return 0;
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    pq.emplace(heightMap[i][j], i, j);
                    vis[i][j] = 1;
                }
            }
        }

        int water = 0;

        while (pq.size()) {
            auto [height, x, y] = pq.top();

            pq.pop();

            for (auto d : dir) {
                int row = x + d[0];
                int col = y + d[1];

                if (row >= 0 && col >= 0 && row < n && col < m &&
                    !vis[row][col]) {
                    vis[row][col] = 1;
                    if (heightMap[row][col] < height) {
                        water += (height - heightMap[row][col]);
                    }

                    pq.emplace(max(height, heightMap[row][col]), row, col);
                }
            }
        }

        return water;
    }
};