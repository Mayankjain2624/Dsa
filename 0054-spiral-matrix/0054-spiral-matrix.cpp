class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x=0;
        vector<int>ans;
        int m=matrix.size();
        int n=matrix[0].size();
        while(x<ceil(min(m,n)*1.0/2)){
            for(int j=x;j<n-x;j++){
                ans.push_back(matrix[x][j]);
            }
            for(int i=x+1;i<m-x;i++){
                ans.push_back(matrix[i][n-x-1]);
            }
            if(m-x-1!=x){
            for(int j=n-x-2;j>=x;j--){
                ans.push_back(matrix[m-x-1][j]);
            }
            }
            if(n-x-1!=x){
            for(int i=m-x-2;i>x;i--){
                ans.push_back(matrix[i][x]);
            }
            }
            x++;
        }
        return ans;
    }
};