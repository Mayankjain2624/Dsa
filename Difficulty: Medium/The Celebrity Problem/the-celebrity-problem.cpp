class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int l=0,r=n-1;
        while(l<=r){
            // cout<<l<<r<<endl;
            if(l==r)
            {
                for(int i=0;i<n;i++){
                    if(mat[i][r]==0)
                    return -1;
                }
                for(int j=0;j<n;j++)
                {
                    if(mat[l][j]==1 && j!=l)
                    return -1;
                }
            return l;
            }
            if(mat[l][r]==mat[r][l]){
                l++;
                r--;
                // cout<<mat[l][r]<<" "<<mat[r][l]<<endl;
                // // cout<<mat[0][2]<<endl;
            }
            else if(mat[l][r]==1){
                l++;
            }
            else if(mat[r][l]==1)
            r--;
        }
        return -1;
    }
};








