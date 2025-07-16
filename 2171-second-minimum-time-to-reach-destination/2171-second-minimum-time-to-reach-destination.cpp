class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int>adj[n+1];
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>>q;
        q.push({0,1});
        vector<vector<int>> dist(n+1,vector<int>(2,INT_MAX));
        dist[0][1]=0;
        while(!q.empty()){
            auto [ct,node]=q.front();
            q.pop();
            for(int &adjnode:adj[node]){
                int wt=0;
                if((ct/change)%2==1){
                    wt=change-ct%change;
                }
                int newtime=time+ct+wt;
                if(dist[adjnode][0]>newtime){
                    dist[adjnode][1]=dist[adjnode][0];
                    dist[adjnode][0]=newtime;
                    q.push({newtime,adjnode});
                }
                else if(dist[adjnode][0]<newtime && dist[adjnode][1]>newtime)
                {
                dist[adjnode][1]=newtime;
                q.push({newtime,adjnode});
                }
            }
        }
        return dist[n][1];
        
    }
};