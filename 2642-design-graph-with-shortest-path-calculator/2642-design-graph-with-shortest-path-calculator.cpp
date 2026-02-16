class Graph {
public:
vector<vector<pair<int,int>>>adj;
vector<int>dis;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        dis.assign(n,INT_MAX);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int d=it[2];
            adj[u].push_back({v,d});
        }
    }
    void addEdge(vector<int> edge) {
        int u=edge[0];
        int v=edge[1];
        int d=edge[2];
        adj[u].push_back({v,d});
    }
    int shortestPath(int node1, int node2) {
        int n=adj.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,node1});
        dis[node1]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            if(node==node2)
            {
                dis.assign(n,INT_MAX);
            return d;
            }
            if(d>dis[node])
            continue;
            for(auto &it:adj[node]){
                int neighbour=it.first;
                int wt=it.second;
                if(dis[node]!=INT_MAX && dis[node]+wt<dis[neighbour]){
                    dis[neighbour]=dis[node]+wt;
                    pq.push({dis[neighbour],neighbour});
                }
            }
        }
        dis.assign(n,INT_MAX);
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */