#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    const long long INF = 1e18;

    void dijkstra(
        int src,
        vector<vector<pair<int,int>>>& graph,
        vector<long long>& dist
    ) 
    {
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) 
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &edge : graph[u]) 
            {
                int v = edge.first;
                int w = edge.second;

                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    // tc: O(e log v)

public:
    long long minimumCost(
        string source,
        string target,
        vector<char>& original,
        vector<char>& changed,
        vector<int>& cost
    ) {
        // Build graph
        vector<vector<pair<int,int>>> graph(26);
        for (int i = 0; i < original.size(); i++) 
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            graph[u].push_back({v, cost[i]}); // u -> v (cost)
        }

        vector<vector<long long>> dist(26, vector<long long>(26, INF));
        vector<bool> computed(26, false);

        long long ans = 0;

        for (int i = 0; i < source.size(); i++) 
        {
            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (!computed[s]) 
            {
                dijkstra(s, graph, dist[s]);
                computed[s] = true;
            }

            if (dist[s][t] == INF) 
            {
                return -1;
            }

            ans += dist[s][t];
        }

        return ans;
    }
};


// TC: O(e log v)
// SC: O(26^2)