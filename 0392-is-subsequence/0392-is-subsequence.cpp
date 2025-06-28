class Solution {
public:
    int solve(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        cout<<i<<" "<<j<<endl;
        if(i<0)
        return true;
        if(j==0){
             if(i!=0 || s[0]!=t[0])
             return false;
             else
             return true;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s[i]==t[j])
        dp[i][j]=solve(s,t,i-1,j-1,dp);
        else
        dp[i][j]=solve(s,t,i,j-1,dp);
        return dp[i][j];
        
    }
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(m==0 && n==0)
        return true;
        if(m==0)
        return false;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s,t,n-1,m-1,dp);
    }
};