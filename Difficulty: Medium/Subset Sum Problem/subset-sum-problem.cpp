class Solution {
  public:
  bool solve(vector<int>& arr,int ind,int target,vector<vector<int>>&dp){
      if(target==0)
      return true;
      if(ind==0){
          if(arr[0]==target)
          return true;
          else
          return false;
      }
      if(dp[ind][target]!=-1)
      return dp[ind][target];
      bool take=false;
      if(arr[ind]<=target)
      take=solve(arr,ind-1,target-arr[ind],dp);
      bool nottake=solve(arr,ind-1,target,dp);
      return dp[ind][target]=take||nottake;
      
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,n-1,sum,dp);
        
    }
};