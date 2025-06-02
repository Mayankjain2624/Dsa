class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        if(grid[0][0]==1)
        return 0;
        dp[0][0]=1;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]==0){
                   if(i>0)
                   dp[i][j]+=dp[i-1][j];
                   if(j>0)
                   dp[i][j]+=dp[i][j-1];
               }
           }
       }
        return dp[n-1][m-1];
    }
};