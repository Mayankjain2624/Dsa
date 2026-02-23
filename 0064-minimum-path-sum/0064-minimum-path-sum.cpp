class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=INT_MAX;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=INT_MAX;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1 && j==1)
                {
                    dp[i][j]=grid[i-1][j-1];
                    continue;
                }
                dp[i][j]=grid[i-1][j-1]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};