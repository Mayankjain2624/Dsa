class Solution {
public:
    int maxp = 0;
    unordered_map<int, unordered_map<int, int>> dp;

    int f(vector<int>& nums, int i, int x) {
        if (i == nums.size())
        {
            if(x==maxp)
            return 1;
            else
            return 0;
        }
        if(dp[i].count(x)>0)
        return dp[i][x];
           int pick = f(nums, i + 1, x | nums[i]);
           int notpick = f(nums, i + 1, x);
        return dp[i][x]=pick + notpick;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for (int i : nums) {
            maxp = maxp | i;
        }
        return f(nums, 0, 0);
    }
};