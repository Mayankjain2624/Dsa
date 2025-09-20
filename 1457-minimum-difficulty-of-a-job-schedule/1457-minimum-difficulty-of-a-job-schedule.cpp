class Solution {
public:
const int INF=1e9;
int solve(int i,int d,vector<int>&job,vector<vector<int>>&dp){
    int n=job.size();
    if(i==n)
    {
        if(d==0)
        return 0;
        else 
        return INF; 
    }
    if(d==0)
    return INF;
    if(dp[i][d]!=-1)
    return dp[i][d];
    int maxi=0;
    int ans=INF;
    for(int j=i;j<n;j++){
          maxi=max(maxi,job[j]);
          int res=solve(j+1,d-1,job,dp);
          if(res!=INF)
          ans=min(maxi+res,ans);
    }
    return dp[i][d]=ans;
}
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        if(d>n)
        return -1;
        return solve(0,d,jobDifficulty,dp);
    }
};