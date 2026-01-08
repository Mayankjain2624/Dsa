class Solution {
public:
    // int solve(vector<int>& nums1, vector<int>& nums2, int i, int j,
    //           vector<vector<int>>& dp) {
    //     if (i >= nums1.size() || j >= nums2.size())
    //         return INT_MIN;
    //     if (dp[i][j] != INT_MIN)
    //         return dp[i][j];
    //     int op1 =
    //         nums1[i] * nums2[j] + max(0, solve(nums1, nums2, i + 1, j + 1, dp));
    //     int op2 = solve(nums1, nums2, i, j + 1, dp);
    //     int op3 = solve(nums1, nums2, i + 1, j, dp);
    //     int op4 = nums1[i] * nums2[j];
    //     return dp[i][j] = max({op1, op2, op3, op4});
    // }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));
        vector<int>curr(m+1,INT_MIN);
        vector<int>next(m+1,INT_MIN);
        for (int i = n - 1; i >= 0; i--) {
              fill(curr.begin(), curr.end(), INT_MIN);
            for (int j = m - 1; j >= 0; j--) {
                int op1 = nums1[i] * nums2[j] + max(0, next[j + 1]);
                int op2 = curr[j + 1];
                int op3 = next[j];
                int op4 = nums1[i] * nums2[j];
                curr[j]= max({op1, op2, op3, op4});
            }
            next=curr;
        }
        return curr[0];
    }
};