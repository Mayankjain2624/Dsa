class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int>adj[V];
        for(auto &it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(V,-1);
        color[0]=1;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int x:adj[node]){
                if(color[x]==-1)
                {
                    q.push(x);
                    color[x]=!color[node];
                }
                else
                {
                    if(color[x]==color[node])
                    return false;
                }
            }
        }
        return true;
        
    }
};