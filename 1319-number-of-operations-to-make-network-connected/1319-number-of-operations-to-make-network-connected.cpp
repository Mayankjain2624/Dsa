class DisjointSet{
    vector<int>rank,parent,size;
public:    
    //intitial constructor
    DisjointSet(int n){
        // rank.resize(n,0);
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    //it will find the ultimate parent and do path compression also so that if next time
    // someone needs parent then no need of doing log n operations
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
     void UnionBySize(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        if(ulp_u==ulp_v)
        return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int noc=connections.size();
        if(noc<n-1)
        return -1;
        DisjointSet ds(n);
        for(auto &it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findPar(u)!=ds.findPar(v)){
                ds.UnionBySize(u,v);
            }
        }
       int nocc=ds.countnocc();
       return nocc-1;
    }
};