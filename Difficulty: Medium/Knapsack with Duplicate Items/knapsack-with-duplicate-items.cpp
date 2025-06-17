// User function Template for C++

class Solution {
  public:
  int solve(vector<int>& val, vector<int>& wt, int i,int c,vector<vector<int>>&dp){
      if(i==0){
              return (c/wt[i])*val[i];
      }
      if(dp[i][c]!=-1)
      return dp[i][c];
      int notpick=solve(val,wt,i-1,c,dp);
      int pick=0;
      if(wt[i]<=c)
      {
          pick=solve(val,wt,i,c-wt[i],dp)+val[i];
      }
      return dp[i][c]=max(pick,notpick);
  }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=wt.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return solve(val,wt,n-1,capacity,dp);
    }
};