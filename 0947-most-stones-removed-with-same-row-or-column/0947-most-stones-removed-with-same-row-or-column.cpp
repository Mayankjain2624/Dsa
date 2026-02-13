// class Solution {
// public:
//     void dfs(vector<vector<int>>& stones, map<pair<int,int>,int>&vis, int ui,
//             int vi) {
//         vis[{ui,vi}] = 1;
//         for (auto& it : stones) {
//             int i = it[0];
//             int j = it[1];
//             if(i==ui || j==vi ){
//                 if(vis.find({i,j})==vis.end()){
//                     dfs(stones,vis,i,j);
//                 }
//             }
//         }
//     }
//     int removeStones(vector<vector<int>>& stones) {
//         map<pair<int,int>,int>vis;
//         int count = 0;
//         for (auto& it : stones) {
//             int i = it[0];
//             int j = it[1];
//             if (vis.find({i,j})==vis.end()) {
//                 count++;
//                 dfs(stones, vis, i, j);
//             }
//         }
//         return stones.size()-count;
//     }
// };
class DisjointSet {
    vector<int> rank, parent, size;

public:
    // intitial constructor
    DisjointSet(int n) {
        // rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    // it will find the ultimate parent and do path compression also so that if
    // next time
    //  someone needs parent then no need of doing log n operations
    int findPar(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = findPar(parent[u]);
    }
    // void UnionByRank(int u, int v) {
    //     int ulp_u = findPar(u);
    //     int ulp_v = findPar(v);
    //     if (ulp_u == ulp_v)
    //         return;
    //     else if (rank[ulp_u] > rank[ulp_v]) {
    //         parent[ulp_v] = ulp_u;
    //     } else if (rank[ulp_v] > rank[ulp_u]) {
    //         parent[ulp_u] = ulp_v;
    //     } else {
    //         parent[ulp_v] = ulp_u;
    //     }
    // }
    void UnionBySize(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    int countnocc(){
        int count=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==i)
            count++;
        }
        return count;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    ds.UnionBySize(i, j);
                }
            }
        }
        int nocc=ds.countnocc();
        return n-nocc+1;
    }
};