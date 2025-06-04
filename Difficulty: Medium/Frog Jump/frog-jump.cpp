class Solution {
  public:
   int f(vector<int>&heights,int i,vector<int>&dp){
        if(i==heights.size()-1)
        return 0;
        int op1=1e9,op2=1e9;
        if(dp[i]!=-1)
        return dp[i];
        if(i+1<heights.size())
        op1=f(heights,i+1,dp)+abs(heights[i+1]-heights[i]);
        if(i+2<heights.size())
        op2=f(heights,i+2,dp)+abs(heights[i+2]-heights[i]);
        return dp[i]=min(op1,op2);
   }
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int>dp(n+1,-1);
        int ans=f(height,0,dp);
        return ans;
    }
};