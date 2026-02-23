class Solution {
public:
    int solve(string &word1, string &word2,int i,int j,vector<vector<int>>&dp){
        if(i<0 && j<0)
        return 0;
        if(i<0)
        return j+1;
        if(j<0)
        return i+1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int cost=0;
        if(word1[i]==word2[j])
        {
            cost=solve(word1,word2,i-1,j-1,dp);
        }
        else{
            int ie=1+solve(word1,word2,i,j-1,dp);
            int de=1+solve(word1,word2,i-1,j,dp);
            int re=1+solve(word1,word2,i-1,j-1,dp);
            cost=min({ie,de,re});
        }
        return dp[i][j]=cost;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return solve(word1,word2,n-1,m-1,dp);
        if(n==0)
        return m;
        if(m==0)
        return n;
        for(int i=0;i<=n;i++){
    dp[i][0]=i;
}
for(int j=0;j<=m;j++){
    dp[0][j]=j;
}
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int ie=1+dp[i][j-1];
                    int de=1+dp[i-1][j];
                    int re=1+dp[i-1][j-1];
                    dp[i][j]=min({ie,re,de});
                }
            }
        }
        return dp[n][m];
    }
};