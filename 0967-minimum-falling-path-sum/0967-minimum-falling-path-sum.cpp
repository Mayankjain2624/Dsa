class Solution {
public:
    // int solve(vector<vector<int>>& matrix,int i,int j){
    //     if(j<0 || j>=matrix[0].size())
    //     return 1000000;
    //     if(i==0)
    //     return matrix[i][j];
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];
    //     int up=matrix[i][j]+solve(matrix,i-1,j);
    //     int left=matrix[i][j]+solve(matrix,i-1,j-1);
    //     int right=matrix[i][j]+solve(matrix,i-1,j+1);
    //  return dp[i][j]=min({up,left,right});
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int m=matrix.size();
        int n=matrix[0].size();
        int mini=10000000;
        //  for(int i=0;i<n;i++){
        //     mini=min(solve(matrix,m-1,i),mini);
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0)
                dp[0][j]=matrix[i][j];
                else
                {
                    int left=1000000,right=1000000;
                    int up=matrix[i][j]+dp[i-1][j];
                    if(j>0)
                    left=matrix[i][j]+dp[i-1][j-1];
                    if(j<n-1)
                    right=matrix[i][j]+dp[i-1][j+1];
                   dp[i][j]=min({up,left,right});
                }
            }
        }

        for(int j=0;j<n;j++){
            mini=min(mini,dp[m-1][j]);
        }
         return mini;
    }
};