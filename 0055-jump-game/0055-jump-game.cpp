class Solution {
public:
    int solve(vector<int>&nums,int i,vector<int>&dp){
        if(i>=nums.size()-1)
            return true;
        if(nums[i]==0)
        return false;
        if(dp[i]!=-1)
            return dp[i];
        bool ans=false;
        for(int j=1;j<=nums[i];j++){
            if(ans==true)
            break;
            if(i+j<nums.size())
            ans=ans || solve(nums,i+j,dp);
        }
        return dp[i]=ans;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};