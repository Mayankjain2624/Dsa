class Solution {
  public:
    // Complete this function
   
    long long int count(long long int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;
         vector<int>coins={3,5,10};
         for(int coin:coins){
             for(int i=coin;i<=n;i++){
                 dp[i]+=dp[i-coin];
             }
         }
         return dp[n];
    }
};