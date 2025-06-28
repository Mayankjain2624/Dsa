class Solution {
public:
    // int solve(string &s,string &t,int i,int j,vector<vector<int>>&dp){
    //     cout<<i<<" "<<j<<endl;
    //     if(i<0)
    //     return true;
    //     if(j==0){
    //          if(i!=0 || s[0]!=t[0])
    //          return false;
    //          else
    //          return true;
    //     }
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];
    //     if(s[i]==t[j])
    //     dp[i][j]=solve(s,t,i-1,j-1,dp);
    //     else
    //     dp[i][j]=solve(s,t,i,j-1,dp);
    //     return dp[i][j];

    // }
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int j=0;j<=m;j++){
            dp[0][j]=1;
        }
        if(s[0]==t[0])
        {
        for (int j = 1; j <= m; j++) {
            dp[1][j] = 1;
        }

        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};