class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        // if(a[0]==b[0])
        return a[1]<b[1];
        // else
        // return a[0]<b[0];
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),comp);
        int maxi=0;
        for(auto &it:events){
            // cout<<it[0]<<" "<<it[1]<<endl;
            maxi=max(it[1],maxi);
        }
        vector<int>used;
        for(int i=1;i<=maxi;i++)
        used.push_back(i);
        int lastused=-1;
        int ans=0;
        for(auto &it:events){
            int start=it[0];
            int end=it[1];
            auto itr=lower_bound(used.begin(),used.end(),start);
            if(itr!=used.end() && *itr<=end)
            {
                ans++;
                used.erase(itr);
            }
        }
        return ans;
    }
};