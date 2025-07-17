class Solution {
public:
    using ll = long long;
    using pii = pair<ll, ll>;

    vector<ll> dijkstra(int src, const vector<vector<pii>>& adj) {
        int n = adj.size();
        vector<ll> dist(n, LLONG_MAX);
        priority_queue<pii, vector<pii>, greater<>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;

            for (const auto& [v, w] : adj[u]) {
                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    ll minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pii>> adj(n), radj(n);

        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].emplace_back(v, w);
            radj[v].emplace_back(u, w); 
        }

        vector<ll> d1 = dijkstra(src1, adj);
        vector<ll> d2 = dijkstra(src2, adj);
        vector<ll> dd = dijkstra(dest, radj);

        ll res = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            if (d1[i] == LLONG_MAX || d2[i] == LLONG_MAX || dd[i] == LLONG_MAX) 
            continue;
            res = min(res, d1[i] + d2[i] + dd[i]);
        }

        return res == LLONG_MAX ? -1 : res;
    }
};
