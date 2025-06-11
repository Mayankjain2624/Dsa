// class Solution {
// public:
//     int solve(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>&dp){
//           if(i==triangle.size()-1)
//           return triangle[i][j];
//           if(dp[i][j]!=-1)
//           return dp[i][j];
//           int d=solve(triangle,i+1,j,dp)+triangle[i][j];
//           int dr=solve(triangle,i+1,j+1,dp)+triangle[i][j];
//           return dp[i][j]=min(d,dr);
          
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n=triangle.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         // return solve(triangle,0,0,dp);
//         for(int i=0;i<n;i++){
//             for(int j=0;j<=i;j++){
//                 if(i==0 && j==0)
//                 dp[i][j]=triangle[i][j];
//                 else{
//                     int up=1000000;
//                     int lup=1000000;
//                     if(i>0)
//                      up=dp[i-1][j]+triangle[i][j];
//                      if(i>0 &&j>0)
//                     lup=dp[i-1][j-1]+triangle[i][j];
//                     dp[i][j]=min(up,lup);
//                 }
//             }
//         }
//         int mini=10000000;
//         for(int j=0;j<n;j++){
//             mini=min(mini,dp[n-1][j]);
//         }
//         return mini;
//     }
// };

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp = triangle;
        
        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};