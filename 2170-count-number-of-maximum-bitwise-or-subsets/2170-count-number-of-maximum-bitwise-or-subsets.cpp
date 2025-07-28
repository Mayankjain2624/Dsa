class Solution {
public:
    int maxp = 0;
    unordered_map<int, unordered_map<int, int>> dp;

    int f(vector<int>& nums, int i, int x,vector<vector<int>>&dp) {
        if (i == nums.size())
        {
            if(x==maxp)
            return 1;
            else
            return 0;
        }
        if(dp[i][x]!=-1)
        return dp[i][x];
           int pick = f(nums, i + 1, x | nums[i],dp);
           int notpick = f(nums, i + 1, x,dp);
        return dp[i][x]=pick + notpick;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for (int i : nums) {
            maxp = maxp | i;
        }
        vector<vector<int>>dp(nums.size(),vector<int>(maxp+1,-1));
        return f(nums, 0, 0,dp);
    }
};