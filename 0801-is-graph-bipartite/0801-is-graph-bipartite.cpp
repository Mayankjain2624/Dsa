class Solution {
public:
    // bool dfs(vector<vector<int>>& graph, vector<int> &color, int col, int node) {
    //     color[node] = col;
    //     for (int i : graph[node]) {
    //         if (color[i] == -1) {
    //             if (dfs(graph, color,!col,i) == false) {
    //                 return false;
    //             }
    //         } else if (color[i] == col) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    //using bfs
    bool check(vector<vector<int>>& graph,vector<int>&color,int start){
        int V = graph.size();
        
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i:graph[node]){
                if(color[i]==-1)
                {
                q.push(i);
                color[i]=!color[node];
                }
                else if(color[i]==color[node])
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V, -1);
        for(int i=0;i<V;i++){
            if(color[i]==-1)
            {
                bool c=check(graph,color,i);
                if(c==false)
                return false;
            }
        }
        return true;
        // for (int i = 0; i < V; i++) {
        //     if (color[i] == -1)
        //     {
        //         if (dfs(graph, color, 0, i) == false)
        //             return false;
        //     }
        // }
        // return true;
    }
};