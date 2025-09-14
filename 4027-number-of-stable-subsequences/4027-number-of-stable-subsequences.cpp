class Solution {
public:
#define ll long long int
ll mod=1e9+7;
    ll fun(vector<int>& nums, vector<vector<vector<ll>>>& dp, int i, int last, int cnt) {
        if (i == -1) {
            if (cnt <= 2)
                return 1;
            else
                return 0;
        }
        ll take = 0;
        ll nottake = 0;
        if (dp[i][last][cnt] != -1)
            return dp[i][last][cnt];
        int pl = (nums[i] % 2);
        if (pl == last) {
            if (cnt < 2)
                take = fun(nums,dp, i - 1, last, cnt + 1);
        } else
            take = fun(nums,dp, i - 1, pl, 1);
        nottake = fun(nums,dp, i - 1, last, cnt);
        dp[i][last][cnt] = (take%mod+ nottake%mod)%mod;
        return dp[i][last][cnt];
    }
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
         vector<vector<vector<ll>>> dp(n + 1,
        vector<vector<ll>>(3, vector<ll>(4, -1)));
        int ans = fun(nums,dp, n - 1, 2, 0);
        return ans - 1;
    }
};