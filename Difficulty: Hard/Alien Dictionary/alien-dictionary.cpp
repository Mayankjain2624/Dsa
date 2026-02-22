class Solution {
  public:
    string solve(unordered_map<int,vector<int>>&adj,unordered_map<int,int>&indegree){
        string topo;
        queue<int>q;
        for(auto &it:indegree){
            if(it.second==0)
            q.push(it.first);
        }
        while(!q.empty()){
            int top=q.front();
            topo.push_back(top+'a');
            q.pop();
            for(int i:adj[top]){
                indegree[i]--;
                if(indegree[i]==0)
                q.push(i);
            }
        }
        // cout<<topo<<endl;
        if(topo.length()!=indegree.size())
        return "";
        return topo;
    }
    string findOrder(vector<string> &words) {
        // code here
        unordered_map<int,int>indegree;
        unordered_map<int,vector<int>>adj;
        int n=words.size();
        for(string &s:words){
             for(char c:s){
                 int i=c-'a';
                 if(indegree.find(i)==indegree.end())
                 indegree[i]=0;
            }
        }
        for(int i=0;i<n-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int k=0;
            while(k<s1.size() && k<s2.size()){
                if(s1[k]!=s2[k]){
                    indegree[s2[k]-'a']++;
                    adj[s1[k]-'a'].push_back(s2[k]-'a');
                    break;
                }
                k++;
            }
             if(k == s2.size() && s1.size() > s2.size())
                return "";
        }
       return solve(adj,indegree);
    }
};