class DisjointSet{
    vector<int>rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findPar(int u){
        if(u==parent[u])
        return u;
        return parent[u]=findPar(parent[u]);
    }
    // void UnionByRank(int u,int v){
    //     int ulp_u=findPar(u);
    //     int ulp_v=findPar(v);
    //     if(ulp_u==ulp_v)
    //     return;
    //     else if(rank[ulp_u]>rank[ulp_v]){
    //         parent[ulp_v]=ulp_u;
    //     }
    //     else if(rank[ulp_v]>rank[ulp_u]){
    //         parent[ulp_u]=ulp_v;
    //     }
    //     else{
    //         parent[ulp_v]=ulp_u;
    //     }
    // }
     bool Union(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        if(ulp_u==ulp_v)
        return false;
        parent[ulp_v]=ulp_u;
        return true;
    }

};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>p1,p2;
        vector<int>parent(n+1,0);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            if(parent[v]!=0){
                p1={parent[v],v};
                p2={u,v};
                it[1]=0;
                break;
            }
            else
            parent[v]=u;
        }
        DisjointSet dsu(n+1);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            if(v==0)
            continue;
            int ulpu=dsu.findPar(u);
            int ulpv=dsu.findPar(v);
            if(!dsu.Union(u,v)){
                if(p1.empty()){
                    return it;
                }
                return p1;
            }
        }
       
        return p2;
    }
};