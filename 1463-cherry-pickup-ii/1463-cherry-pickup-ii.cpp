class Solution {
public:
    // int solve(vector<vector<int>>& grid, int i, int j1, int j2, int n, int m,
    //           vector<vector<vector<int>>>& dp) {
    //     if (i == n)
    //         return 0;
    //     if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
    //         return 0;
    //     if (i == n - 1 && j1 == j2)
    //         return grid[i][j1];
    //     else if (i == n - 1 && j1 != j2)
    //         return grid[i][j1] + grid[i][j2];
    //     if (dp[i][j1][j2] != -1)
    //         return dp[i][j1][j2];
    //     int maxCandy = 0;
    //     int current = 0;
    //     if (j1 == j2)
    //         current = grid[i][j1];
    //     else
    //         current = grid[i][j1] + grid[i][j2];
    //     for (int d1 = -1; d1 <= 1; d1++) {
    //         for (int d2 = -1; d2 <= 1; d2++) {
    //             int n1 = j1 + d1;
    //             int n2 = j2 + d2;
    //             maxCandy = max(maxCandy,
    //                            current + solve(grid, i + 1, n1, n2, n, m, dp));
    //         }
    //     }
    //     return dp[i][j1][j2] = maxCandy;
    // }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(m, vector<int>(m, 0)));
        // return solve(grid, 0, 0, m - 1, n, m, dp);
        for (int i = n - 1; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxCandy = 0;
                    int current = 0;
                    if (j1 == j2)
                        current = grid[i][j1];
                    else
                        current = grid[i][j1] + grid[i][j2];
                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {
                            int n1 = j1 + d1;
                            int n2 = j2 + d2;
                            if (n1 < 0 || n2 < 0 || n1 >= m || n2 >= m)
                            continue;
                            maxCandy = max(maxCandy, current + dp[i + 1][n1][n2]);
                        }
                    }
                    dp[i][j1][j2]=maxCandy;
                }
            }
        }
        return dp[0][0][m-1];
    }
};