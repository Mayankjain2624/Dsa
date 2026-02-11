class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0;
        int r=n-1;
        int fr=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(target>=matrix[mid][0])
            {
                fr=mid;
                l=mid+1;
            }
            else
            r=mid-1;
        }
        l=0,r=m-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(target==matrix[fr][mid])
            return true;
            else if(target<matrix[fr][mid])
            r=mid-1;
            else
            l=mid+1;

        }
        return false;
    }
};