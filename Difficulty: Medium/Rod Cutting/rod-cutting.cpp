// User function Template for C++

class Solution {
  public:
    int solve(vector<int> &price,int i,int r){
        if(i==0){
            return r*price[0];
        }
        int notpick=solve(price,i-1,r);
        int pick=0;
        if(i+1<=r)
        pick=price[i]+solve(price,i,r-i-1);
        return max(pick,notpick);
    }
    int cutRod(vector<int> &price) {

        int n=price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);
         for(int i=0;i<=n;i++)
            prev[i] = i*price[0];
       for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                
                int nt = prev[j];
                int t = INT_MIN;
                
                int rl = i+1;
                if(rl<=j)
                    t = price[i] + curr[j-rl];
                
                curr[j] = max(nt,t);
            }
            prev=curr;
        }
        return prev[n];
    }
};