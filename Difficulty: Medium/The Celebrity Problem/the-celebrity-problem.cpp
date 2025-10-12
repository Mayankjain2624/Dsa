class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int l=0;
        int r=mat.size()-1;
        while(l<=r){
            if(l==r)
            {
                for(int i=0;i<mat.size();i++){
                    if(mat[i][l]==0)
                    return -1;
                }
                for(int i=0;i<mat.size();i++){
                    if(l==i)
                    continue;
                    if(mat[l][i]==1)
                    return -1;
                }
                return l;
            }
            if(mat[l][r]==1 && mat[r][l]==1)
            {
                l++;
                r--;
            }
            else if(mat[l][r]==0 && mat[r][l]==0){
                l++;
                r--;
            }
            else if(mat[l][r]==1)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return -1;
    }
};