class Solution {
public:
    // int solve(vector<int>& nums,int i,int prev,vector<vector<int>>&dp){
    //     if(i==nums.size())
    //     return 0;
    //     if(dp[i][prev+1])
    //     return dp[i][prev+1];
    //     int nottake=solve(nums,i+1,prev,dp);
    //     int take=0;
    //     if(prev==-1 || nums[i]%nums[prev]==0)
    //     take=solve(nums,i+1,i,dp);
    //     return dp[i][prev+1]=max(take,nottake);
    // }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n+2,vector<int>(n+1,0));
        sort(nums.begin(),nums.end());
        // int len=solve(nums,0,-1,dp);
        // for(int i=n-1;i>=0;i--){
        //     for(int prev=i-1;prev>=-1;prev--){
        //          int nottake=dp[i+1][prev+1];
        //          int take=0;
        //          if(prev==-1 || nums[i]%nums[prev]==0)
        //          take=1+dp[i+1][i+1];
        //          dp[i][prev+1]=max(take,nottake);
        //     }
        // }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // int i=n-1,j=n-1;
        // vector<int>ans;
        // while(i>=0 && j>=1){
        //     if(nums[i]%nums[j-1]==0){
        //         ans.push_back(nums[i]);
        //         i--;
        //         j--;
        //     }
        //     else
        //     {
        //            i--;
        //     }
                
        // }
        // return ans;
        vector<int>dp(n,1),hash(n,-1);
        int l=0;
        int maxi=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                    // l=max(l,i);
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                l=i;
            }

        }
        vector<int>ans;
        while(l!=-1){
            ans.push_back(nums[l]);
            l=hash[l];
        }
        
        return ans;
    }
};
