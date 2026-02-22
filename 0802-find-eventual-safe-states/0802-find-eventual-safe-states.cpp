class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>&vis,vector<int>&pathvis,int i,vector<int>&safe){
        vis[i]=1;
        pathvis[i]=1;
        if(safe[i]==1)
        return true;
        for(int nei:graph[i]){
            if(!vis[nei]){
                if(dfs(graph,vis,pathvis,nei,safe)==false)
                return false;
            }
            else if(pathvis[nei])
            return false;
        }
        pathvis[i]=0;
        safe[i]=1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0),pathvis(n,0),safe(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])
            dfs(graph,vis,pathvis,i,safe);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(safe[i]==1)
            ans.push_back(i);
        }
        return ans;
    }
};
// 0 1 2 3 4 5 6
// 1 1 1



// 0 0 1 0 0 1 0
// dfs(0)->dfs(1)->dfs(3)->