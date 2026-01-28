class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> costs(n, vector<int> (m, INT_MAX));
        vector<pair<int, int>> gridPoints;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                gridPoints.push_back({i, j});
            }
        }
        sort(gridPoints.begin(), gridPoints.end(), [&](pair<int, int>& a, pair<int, int>& b) {
            return grid[a.first][a.second] < grid[b.first][b.second];
        });

        while (k-- >= 0) {
            int minCost = INT_MAX;
            for (int i = 0; i < gridPoints.size(); i++) {
                int r = gridPoints[i].first;
                int c = gridPoints[i].second;
                minCost = min(minCost, costs[r][c]);
                if (i + 1 < gridPoints.size() && grid[r][c] == grid[gridPoints[i + 1].first][gridPoints[i + 1].second]) {
                    continue;
                }
                int back = i;
                while (back >= 0 && grid[r][c] == grid[gridPoints[back].first][gridPoints[back].second]) {
                    costs[gridPoints[back].first][gridPoints[back].second] = minCost;
                    back--;
                }
            }

            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    if (i == n - 1 && j == m - 1) {
                        costs[i][j] = 0;
                    }
                    if (i + 1 < n) {
                        costs[i][j] = min(costs[i][j], costs[i + 1][j] + grid[i + 1][j]);
                    }
                    if (j + 1 < m) {
                        costs[i][j] = min(costs[i][j], costs[i][j + 1] + grid[i][j + 1]);
                    }
                }
            }
        }
        return costs[0][0];
    }
};