class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=coins.size();
        vector<vector<int>>adj(n);
        // if(n<=3)
        // return 0;
        vector<int>deg(n,0);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            deg[u]++;
            deg[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
         for(int i:deg)
        cout<<i<<" ";
        cout<<endl;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(deg[i]==1 && coins[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            deg[node]--;
            for(int i:adj[node]){
                deg[i]--;
                if(deg[i]==1 && coins[i]==0)
                    q.push(i);
            }
        }
         for(int i:deg)
        cout<<i<<" ";
        cout<<endl;
        for(int k=0;k<2;k++){
        queue<int>q2;
        for(int i=0;i<n;i++){
            if(deg[i]==1)
            q2.push(i);
        }
        while(!q2.empty()){
            int node=q2.front();
            q2.pop();
            int parent=0;
            deg[node]=0;
            for(int i:adj[node])
            {
                if(deg[i]>0)
                deg[i]--;
            }
        }
        }
        int re=0;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            if(deg[u]>0 && deg[v]>0)
            re++;
        }
        for(int i:deg)
        cout<<i<<" ";
        cout<<endl;
        return re*2;
    }
};