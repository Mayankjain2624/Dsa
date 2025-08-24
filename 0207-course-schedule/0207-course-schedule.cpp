class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<int>adj[V];
        vector<int>dis(V,INT_MAX);
        vector<int>indegree(V);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int>q;
        // vector<int>topo;
        int topo=0;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            // topo.push_back(node);
            topo++;
            q.pop();
            for(auto &pr:adj[node]){
                indegree[pr]--;
                if(indegree[pr]==0)
                q.push(pr);
            }
        }
        if(topo==V)
        return true;
        return false;
    }
};