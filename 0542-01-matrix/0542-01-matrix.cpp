class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        // vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)
                {
                    // vis[i][j]=1;
                q.push({{i,j},0});
                }
            }
        }
        int ad=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int dis=q.front().second;
            ans[r][c]=dis;
            q.pop();
            for(int di=-1;di<=1;di++){
                for(int dj=-1;dj<=1;dj++){
                    if(di==0 || dj==0){
                        int nr=r+di;
                        int nc=c+dj;
                        if(nr>=0 &&nr<n && nc>=0 &&nc<m){
                            if(mat[nr][nc]==1){
                                mat[nr][nc]=0;
                                q.push({{nr,nc},dis+1});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};