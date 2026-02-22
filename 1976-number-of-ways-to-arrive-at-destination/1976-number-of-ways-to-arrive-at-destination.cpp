class Solution {
    int N = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long>time(n,LLONG_MAX);
        time[0]=0;
        vector<long long>ways(n,0);
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            long long d=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            for(auto &it:adj[node]){
                long long nei=it.first;
                long long cost=it.second;
                if(d+cost<time[nei]){
                    time[nei]=d+cost;
                    pq.push({d+cost,nei});
                    ways[nei]=ways[node]%N;
                }
                else if(d+cost==time[nei]){
                    ways[nei]=(ways[nei]%N+ways[node]%N)%N;
                }
            }
        }
        return ways[n-1];
    }
};