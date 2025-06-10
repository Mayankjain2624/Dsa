//dijstra solution(my first intitution)

// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
//         pq.push({grid[0][0],{0,0}});
//         int ans=0;
//         if(m==1 && n==1)
//         return grid[0][0];
//         vector<vector<int>>cost(m,vector<int>(n,1e9));
//         while(!pq.empty()){
//             int c=pq.top().first;
//             int x=pq.top().second.first;
//             int y=pq.top().second.second;
//             ans+=c;
//             pq.pop();
//             if(x<m-1 &&  cost[x+1][y]>c+grid[x+1][y])
//             {
//             cost[x+1][y]=c+grid[x+1][y];
//             pq.push({cost[x+1][y],{x+1,y}});
//             }
//             if(y<n-1 &&cost[x][y+1]>c+grid[x][y+1])
//             {
//                 cost[x][y+1]=c+grid[x][y+1];
//                 pq.push({cost[x][y+1],{x,y+1}});
//             }
//         }
//         return cost[m-1][n-1];
//     }
// };


class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        if(i==0 && j==0)
        return grid[0][0];
        if(i<0 || j<0)
        return 1000000;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int left=solve(grid,i,j-1,dp)+grid[i][j];
        int up=solve(grid,i-1,j,dp)+grid[i][j];
        return dp[i][j]=min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(grid,m-1,n-1,dp);
    }
};