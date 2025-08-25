class Solution {
public:
        vector<int> ans;
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis,
             vector<int>& pv) {
        vis[node] = 1;
        pv[node] = 1;
        // check[node] = 0;
        for (int i : graph[node]) {
            if (!vis[i]) {

                if (dfs(i, graph, vis, pv) == true) {
                    // check[node] = 0;
                    return true;
                }
            } else if (pv[i] == 1) {
                // check[node] = 0;
                return true;
            }
        }
        // check[node] = 1;
        ans.push_back(node);
        pv[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V,0);
        vector<int> pv(V,0);
        // vector<int> check(V,0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pv);
            }
        }

        // for (int i = 0; i < V; i++) {
        //     if (check[i] == 1)
        //         ans.push_back(i);
        // }
        sort(ans.begin(),ans.end());
        return ans;
    }
};