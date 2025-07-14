class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> adj(n);
        // map < pair<int, int>, int >> mp;
        for (auto& e : edges) {
    int u = e[0], v = e[1], w = e[2];
    adj[u].push_back({v, w + 1});
    adj[v].push_back({u, w + 1});
}
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        dist[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto top = pq.top();
            int d = top.first;
            int node = top.second;
            pq.pop();
            if (d > dist[node])
                continue;
            for (auto& it : adj[node]) {
                int edgeweight = it.second;
                int adjnode = it.first;
                int eff = d + edgeweight;
                if (eff < dist[adjnode]) {
                    dist[adjnode]=eff;
                    pq.push({eff, adjnode});
                }
            }
        }
        int ans = 0;
        for (int &x : dist) {
            if (x <= maxMoves)
                ans += 1;
        }
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            int a = max(0, maxMoves - dist[u]);
            int b = max(0, maxMoves - dist[v]);
            ans += min(w, a + b);
        }
        return ans;
    }
};