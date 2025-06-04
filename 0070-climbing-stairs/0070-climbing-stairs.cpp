class Solution {
public:
        int dp[46];
    
    // Solution() {
    //     std::fill(dp, dp + 46, -1); 
    // }

//     int climbStairs(int n) {
//          if(n<0)
//          return 0;
//          else if(n==0)
//          return 1;
//          else if(dp[n]!=-1)
//          return dp[n];
//          else
//          return dp[n]=climbStairs(n-1)+climbStairs(n-2);
//     }
// };
int climbStairs(int n) {
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}};

