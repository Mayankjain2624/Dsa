// User function template for C++
class Solution {
  public:
      int f(vector<int>&arr,int i,vector<int>&dp){
          if(i==0)
          return arr[0];
          if(i<0)
          return 0;
          if(dp[i]!=-1)
          return dp[i];
          else
          {
              int pick=arr[i]+f(arr,i-2,dp);
              int notpick=0+f(arr,i-1,dp);
              return dp[i]=max(pick,notpick);
          }
          
      }
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        vector<int>dp(arr.size()+1,-1);
        int ans=f(arr,arr.size()-1,dp);
        return ans;
        // cout<<f()
    }
};