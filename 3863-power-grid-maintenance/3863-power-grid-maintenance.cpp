class Solution {
public:
    void dfs(int node, set<int>& curr, vector<int>& vis,
             vector<vector<int>>& adj) {
        vis[node] = 1;
        for (int i : adj[node]) {
            if (!vis[i]) {
                curr.insert(i);
                dfs(i, curr, vis, adj);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        vector<vector<int>> adj(c + 1);
        for (auto& it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(c + 1);
        vector<set<int>> zones;
        for (int i = 1; i <= c; i++) {
            if (!vis[i]) {
                set<int> temp;
                dfs(i, temp, vis, adj);
                temp.insert(i);
                zones.push_back(temp);
            }
        }

       vector<int> ump(c + 1);
        for (int i = 0; i < zones.size(); i++) {
            for (int j : zones[i])
                ump[j] = i;
        }
        vector<int> line(c + 1, 1);
        vector<int> ans;
        for (auto& it : queries) {
            int choice = it[0];
            int x = it[1];
            if (choice == 1) {
                if (line[x] == 1)
                    ans.push_back(x);
                else if (line[x] == 0 && !zones[ump[x]].empty())
                    ans.push_back(*zones[ump[x]].begin());
                else
                    ans.push_back(-1);
            }
            if (choice == 2) {
                line[x] = 0;
                if (!zones[ump[x]].empty()) {
                    zones[ump[x]].erase(x);
                }
            }
        }
        return ans;
    }
};