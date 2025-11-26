class Solution {
public:
    static const int MOD = 1e9 + 7;

    int helper(vector<vector<int>>& grid, int k, int r, int c, int rem,
               vector<vector<vector<int>>>& dp) 
    {
        int n = grid.size(), m = grid[0].size();

        if (r >= n || c >= m) return 0;

        rem = (rem + grid[r][c]) % k;

        if (dp[r][c][rem] != -1) 
            return dp[r][c][rem];

        if (r == n-1 && c == m-1)
            return dp[r][c][rem] = (rem == 0);

        long long right = helper(grid, k, r, c+1, rem, dp);
        long long down  = helper(grid, k, r+1, c, rem, dp);

        return dp[r][c][rem] = (right + down) % MOD;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));

        return helper(grid, k, 0, 0, 0, dp);
    }
};