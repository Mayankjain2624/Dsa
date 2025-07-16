class Solution {
public:
vector<int>dx={0,0,1,-1};
vector<int>dy={1,-1,0,0};
    bool isvalid(int n,int m,int i,int j){
        if(i<n && i>=0 && j<m && j>=0)
        return true;
        return false;
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cost = 0;
       priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        pq.push(make_tuple(0,0,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        while(!pq.empty()){
            int cost=get<0>(pq.top());
            int i=get<1>(pq.top());
            int j=get<2>(pq.top());
            // cout<<i<<j<<endl;
            pq.pop();
            if(i==n-1 && j==m-1)
            return cost;
            if(vis[i][j])
            continue;
            vis[i][j]=1;
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(isvalid(n,m,ni,nj) && !vis[ni][nj]){
                    if(k+1==grid[i][j])
                    pq.push(make_tuple(cost,ni,nj));
                    else
                    pq.push(make_tuple(cost+1,ni,nj));
                }
            }
        }
        return 0;
    }
};