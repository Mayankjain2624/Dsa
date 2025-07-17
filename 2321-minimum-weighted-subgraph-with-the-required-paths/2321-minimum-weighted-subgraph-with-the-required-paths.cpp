class Solution {
public:
    vector<long long> dijstra(long long  src, vector<vector<pair<long long , long long >>>& adj) {
        priority_queue<pair<long long, long long >, vector<pair<long long, long long >>,
                       greater<>>
            pq;
        vector<long long> dist(adj.size(), LLONG_MAX);
        dist[src]=0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            if (cost > dist[node])
                continue;
            for (auto& it : adj[node]) {
                long long  nc = cost + it.second;
                long long  adjnode = it.first;
                if (dist[adjnode] > nc) {
                    dist[adjnode] = nc;
                    pq.push({nc, adjnode});
                }
            }
        }
        return dist;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int  src1,
                            int  src2, int  dest) {
        vector<vector<pair<long long , long long >>> adj(n), radj(n);
        for (auto& it : edges) {
            long long  u = it[0];
            long long  v = it[1];
            long long  w = it[2];
            adj[u].push_back({v, w});
            radj[v].push_back({u, w});
        }
        vector<long long> ds1 = dijstra(src1, adj);
        vector<long long> ds2 = dijstra(src2, adj);
        vector<long long> dfd = dijstra(dest, radj);

        long long minweight = LLONG_MAX;
for (long long i = 0; i < n; i++) {
    if (ds1[i] != LLONG_MAX && ds2[i] != LLONG_MAX && dfd[i] != LLONG_MAX) {
        minweight = min(minweight, ds1[i] + ds2[i] + dfd[i]);
    }
}

        if (minweight == LLONG_MAX)
            return -1;
        return minweight;
    }
};