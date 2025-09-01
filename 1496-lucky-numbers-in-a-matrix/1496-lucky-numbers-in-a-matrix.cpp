class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int>minr;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            int mj=0;
            for(int j=0;j<m;j++){
                if(matrix[i][j]<mini)
                {
                    mj=j;
                    mini=matrix[i][j];
                }
            }
            minr.push_back(mj);
        }
        vector<int>ans;
        for(int j=0;j<minr.size();j++){
            int vj=minr[j];
            int maxi=0;
            int mi=0;
            for(int i=0;i<matrix.size();i++){
                if(matrix[i][vj]>maxi)
                {
                       mi=i;
                       maxi=matrix[i][vj];
                }
            }
            if(mi==j)
            ans.push_back(matrix[mi][vj]);
        }
        return ans;
    }
};