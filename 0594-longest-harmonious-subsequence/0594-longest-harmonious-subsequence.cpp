class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>mp;
        for(int i:nums){mp[i]++;}
        int ans=0;
        vector<pair<int,int>>vp;
        for(auto &it:mp){
            vp.push_back({it.first,it.second});
        }
        for(int i=0;i<vp.size()-1;i++){
            auto it1=vp.begin()+i;
            auto it2=vp.begin()+i+1;
              if(it1->first==(it2->first-1))
               ans=max(ans,it1->second+(it2)->second);
        }
      return ans;
    }
};