class Solution {
public:
bool isValid(int x,int y,int n,int m){
    if(x>=0 && x<n && y>=0 && y<m)
    return true;
    return false;
}
    vector<int>di={1,0,-1,0};
    vector<int>dj={0,1,0,-1};
    void dfs(vector<vector<char>>& grid,int x,int y,int n,int m){
        grid[x][y]='0';
        for(int i=0;i<4;i++){
            int nx=x+di[i];
            int ny=y+dj[i];
            if(isValid(nx,ny,n,m) && grid[nx][ny]=='1'){
                dfs(grid,nx,ny,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return cnt;
    }
};