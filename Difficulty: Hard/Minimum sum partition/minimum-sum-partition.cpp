class Solution {

  public:
    int minDifference(vector<int>& arr) {
        int n=arr.size();
        int s=0;
        for(int i:arr){s+=i;};
        int target=s/2+1;
        vector<vector<int>>dp(n,vector<int>(target,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        if(arr[0]<=target)
        dp[0][arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int t=1;t<target;t++){
                int pick=0;
                if(t>=arr[i])
                pick=dp[i-1][t-arr[i]];
                int notpick=dp[i-1][t];
                dp[i][t]=pick||notpick;
            }
        }
        int mini=1e8;
        for(int t=0;t<target;t++){
            if(dp[n-1][t]==1)
            {
                int s1=t;
                int s2=s-t;
                mini=min(mini,abs(s1-s2));
            }
        }
        return mini;
    }
};
