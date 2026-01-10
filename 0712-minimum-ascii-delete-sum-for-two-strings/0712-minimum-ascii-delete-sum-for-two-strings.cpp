class Solution {
public:
    // int solve(string& s1, string& s2, int i, int j,vector<vector<int>>&dp) {
    //     if (i < 0 && j < 0)
    //         return 0;
    //     if (i < 0) {
    //         int rem = 0;
    //         for (int k = 0; k <= j; k++)
    //             rem += s2[k];
    //         return rem;
    //     }
    //     if (j < 0) {
    //         int rem = 0;
    //         for (int k = 0; k <= i; k++)
    //             rem += s1[k];
    //         return rem;
    //     }
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];
    //     int op1 = 1e9, op2, op3;
    //     if (s1[i] == s2[j]) {
    //         op1 = solve(s1, s2, i - 1, j - 1,dp);
    //     }
    //     op2 = s1[i] + solve(s1, s2, i - 1, j,dp);
    //     op3 = s2[j] + solve(s1, s2, i, j - 1,dp);
    //     return dp[i][j]=min({op1, op2, op3});
    // }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            dp[i][0]=s1[i-1]+dp[i-1][0];
        }
        for(int j=1;j<=m;j++){
            dp[0][j]=s2[j-1]+dp[0][j-1];
        }
        for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    int op1 = 1e9, op2, op3;
                    if(s1[i-1]==s2[j-1])
                    op1=dp[i-1][j-1];
                    op2=s1[i-1]+dp[i-1][j];
                    op3=s2[j-1]+dp[i][j-1];
                    dp[i][j]=min({op1, op2, op3});
                }
        }
        // for(auto i:dp){
        //     for(int j:i)
        //     cout<<j<<" ";
        //     cout<<endl;
        // }
        return dp[n][m];
    }
};