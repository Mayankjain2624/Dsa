class Solution {
public:
vector<int>dx={1,-1,0,0};
vector<int>dy={0,0,1,-1};
bool isvalid(int x,int y,int n,int m){
    if(x>=0 && x<n && y>=0 && y<m)
    return true;
    else
    return false;
}
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        if(grid[0][0]==0)
        pq.push({0,{0,0}});
        else
        pq.push({1,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        // vector<vector<int>>vis(n,vector<int>(m,1e9));
        dist[0][0]=grid[0][0]? 1 : 0;
        while(!pq.empty()){
            auto top=pq.top();
            int cost=top.first;
            int x=top.second.first;
            int y=top.second.second;
            pq.pop();
            if(x==n-1 && y==m-1)
            return cost;
            // if(vis[x][y])
            // continue;
            // vis[x][y]=1;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(isvalid(nx,ny,n,m)){
                     if(grid[nx][ny]==1)
                     {
                        if(dist[nx][ny]>cost+1)
                        {
                            dist[nx][ny]=cost+1;
                        pq.push({cost+1,{nx,ny}});
                        }
                     }
                     else
                     {
                        if(dist[nx][ny]>cost)
                        {
                            dist[nx][ny]=cost;
                     pq.push({cost,{nx,ny}});
                        }
                     }
                }
            }
        }
        return -1;
    }
};