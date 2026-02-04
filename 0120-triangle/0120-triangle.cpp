class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp=triangle;
        // dp[0].push_back(triangle[0][0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                int left=INT_MAX;
                int du=INT_MAX;
                if(j>=1)
                {
                left=dp[i-1][j-1];
                }
                if(j!=i)
                du=dp[i-1][j];
                dp[i][j]=min(left,du)+triangle[i][j];
            }
        }
        int mini=1e9;
        for(int j=0;j<n;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
    }
};