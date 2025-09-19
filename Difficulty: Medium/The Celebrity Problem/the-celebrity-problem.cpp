class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        // int m=mat[0].size();
        if(n==1)
        return 0;
        vector<int>outdegree(n+1),indegree(n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && i!=j)
                {
                outdegree[i]++;
                indegree[j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(outdegree[i]==0 && indegree[i]==n-1)
            return i;
        }
        return -1;
    }
};