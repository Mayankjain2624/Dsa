class Solution {
public:
int solve(int i,int j,vector<vector<int>>&v){
    if(i==0 && j==0)
    return 1;
    if(i<0 || j<0)
    return 0;
    int left=0;
    int up=0;
    if(i>0 && v[i-1][j]==0)
    up=solve(i-1,j,v);
    if(j>0 && v[i][j-1]==0)
    left=solve(i,j-1,v);
    return left+up;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1)
        return 0;
        // return solve(n-1,m-1,obstacleGrid);
                vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)
                dp[i][j]=1;
                else
                {
                    int left=0;
                    int up=0;
                    if(j>0 &&  obstacleGrid[i][j-1]==0)
                    left=dp[i][j-1];
                    if(i>0 &&  obstacleGrid[i-1][j]==0)
                    up=dp[i-1][j];
                    dp[i][j]=left+up;  
                }
            }
        }
        return dp[n-1][m-1];
    }
};