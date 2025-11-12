class Solution {
public:
int dp(int i,int n,vector<int>&dpv)
{
    if(i==n)
    return 1;
    if(i>n)
    return 0;
    if(dpv[i]!=-1)
    return dpv[i];
    return dpv[i]=dp(i+1,n,dpv)+dp(i+2,n,dpv);
}
    int climbStairs(int n) {
        vector<int>dpv(n+1,-1);
        return dp(0,n,dpv);
    }
};