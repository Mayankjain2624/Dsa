class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        // int m=mat[0].size();
        if(n==1)
        return 0;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=0;j<n;j++){
                s+=mat[i][j];
            }
            if(s==1)
            {
                int t=0;
                for(int k=0;k<n;k++){
                    t+=mat[k][i];
                }
                if(t==n)
                return i;
            }
        }
        return -1;
    }
};