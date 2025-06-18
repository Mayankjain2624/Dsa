// User function Template for C++

class Solution {
  public:
    int longestPalinSubseq(string &s) {
        // code here
        string text1=s;
        reverse(s.begin(),s.end());
        string text2=s;
         int n=text1.size();
        int m=text2.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return solve(text1,text2,n-1,m-1,dp);
        // for(int i=0;i<n;i++){
        //     if(text1[i]==text2[0])
        //     dp[i][0]=1;
        // }
        // for(int j=0;j<m;j++){
        //     if(text2[j]==text1[0])
        //     dp[0][j]=1;
        // }
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int match=0,notmatch=0;
                if(text1[i-1]==text2[j-1])
                match=1+prev[j-1];
                else
                {
                    int left=prev[j];
                    int right=curr[j-1];
                    notmatch=max(left,right);
                }
              curr[j]=max(match,notmatch);
            }
            prev=curr;
        }
        return prev[m];
    }
};