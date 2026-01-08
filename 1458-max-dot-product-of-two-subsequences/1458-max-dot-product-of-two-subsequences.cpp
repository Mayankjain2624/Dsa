class Solution {
public:

    int solve(vector<int>& nums1, vector<int>& nums2,int i,int j,vector<vector<int>>&dp){
        if(i>=nums1.size())
        return 0;
        if(j>=nums2.size())
        return 0;
        if(dp[i][j]!=INT_MIN)
        return dp[i][j];
        int op1=nums1[i]*nums2[j]+solve(nums1,nums2,i+1,j+1,dp);
        int op2=INT_MIN;
        if(j+1<nums2.size())
        op2=solve(nums1,nums2,i,j+1,dp);
        int op3=INT_MIN;
        if(i+1<nums1.size())
        op3=solve(nums1,nums2,i+1,j,dp);
        int op4=nums1[i]*nums2[j];
        return dp[i][j]=max({op1,op2,op3,op4});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MIN));
        return solve(nums1,nums2,0,0,dp);
    }

};