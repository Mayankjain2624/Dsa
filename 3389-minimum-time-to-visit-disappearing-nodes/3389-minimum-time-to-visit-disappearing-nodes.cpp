class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:edges){
             int u=it[0];
             int v=it[1];
             int cost=it[2];
             adj[u].push_back({v,cost});
             adj[v].push_back({u,cost});
        }
        vector<int>dist(n,1e9),visited(n,0);
        dist[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        while(!pq.empty()){
             auto top=pq.top();
             int cost=top.first;
             int curr=top.second;
             pq.pop();
             if(visited[curr])
             continue;
             visited[curr]=1;
             for(auto &it:adj[curr]){
                int node=it.first;
                int newcost=cost+it.second;
                if(newcost<dist[node] && newcost<disappear[node])
                {
                    dist[node]=newcost;
                    pq.push({newcost,node});
                }
             }
        }
        for(int i=0;i<n;i++){
            if(dist[i]==1e9)
            dist[i]=-1;
        }
        return dist;
    }
};