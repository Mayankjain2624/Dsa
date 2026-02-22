class Solution {
public:
bool isValid(int x,int y,int n,int m){
    if(x>=0 && x<n && y>=0 && y<m)
    return true;
    return false;
}
    vector<int>di={1,0,-1,0};
    vector<int>dj={0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        // vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    // vis[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }
        int maxTime=0;
        while(!q.empty()){
            int time=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            maxTime=max(maxTime,time);
            for(int i=0;i<4;i++){
                int nx=x+di[i];
                int ny=y+dj[i];
                if(isValid(nx,ny,n,m) && grid[nx][ny]==1){
                    //   vis[nx][ny]=1;
                      grid[nx][ny]=2;
                      q.push({time+1,{nx,ny}});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                return -1;
            }
        }
        return maxTime;
    }
};