class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),comp);
        int maxi=0;
        for(auto &it:events){
            maxi=max(it[1],maxi);
        }
        vector<int>used;
        for(int i=1;i<=maxi;i++)
        used.push_back(i);
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