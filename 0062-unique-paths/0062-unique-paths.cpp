class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        vector<int>prev(n+1,0);
        for(int i=1;i<=m;i++){
        vector<int>curr(n+1,0);
            for(int j=1;j<=n;j++){
                if(i==1 && j==1)
                curr[j]=1;
                curr[j]+=(prev[j]+curr[j-1]);
            }
            prev=curr;
        }
        return prev[n];
    }
};