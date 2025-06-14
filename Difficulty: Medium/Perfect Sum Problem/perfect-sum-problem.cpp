class Solution {
  public:
     int solve(vector<int>& arr,int i, int s,int zc,vector<vector<int>>&dp)
     {
         if(s==0)
         return max((1<<zc),1);
         if(i==0)
         return (arr[i]==s);
         int pick=0;
         if(arr[i]==0)
         zc--;
         if(dp[i][s]!=-1)
         return dp[i][s];
         if(arr[i]<=s)
         pick=solve(arr,i-1,s-arr[i],zc,dp);
         int notpick=solve(arr,i-1,s,zc,dp);
         return dp[i][s]=pick+notpick;
     }
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        int zc=count(arr.begin(),arr.end(),0);
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(arr,n-1,target,zc,dp);
    }
};