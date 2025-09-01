class Solution {
public:
// int maxloot(vector<int>&nums,int i,vector<int>&dp){
//     if(i<0)
//     return 0;
//     if(i==0)
//     return nums[i];
//     if(dp[i]!=-1)
//     return dp[i];
//     else
//     {
//         int take=0,nottake=0;
//         take=nums[i]+maxloot(nums,i-2,dp);
//         nottake=maxloot(nums,i-1,dp);
//         return dp[i]=max(take,nottake);
//     }
// }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        // int ans=maxloot(nums,n-1,dp);
        dp[0]=nums[0];
        if(n>1)
        dp[1]=max(dp[0],nums[1]);
        for(int i=2;i<n;i++){
               dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];

    }
};