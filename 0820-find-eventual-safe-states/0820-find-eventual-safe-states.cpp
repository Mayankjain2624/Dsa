class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adjrev(n);
        vector<int>indegree(n);
        for(int i=0;i<n;i++){
            for(int j:graph[i]){
                adjrev[j].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i:adjrev[node]){
                indegree[i]--;
                if(indegree[i]==0)
                q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};