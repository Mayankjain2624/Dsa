class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
         vector<int>prev(m+1,0),curr(m+1,0);
         int maxi=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int match=0,notmatch=0;
                if(s1[i-1]==s2[j-1])
                match=1+prev[j-1];
                else
                {
                    // int left=prev[j];
                    // int right=curr[j-1];
                    // notmatch=max(left,right);
                }
              curr[j]=max(match,0);
              maxi=max(maxi,curr[j]);
            }
            prev=curr;
        }
        return maxi;
    }
};