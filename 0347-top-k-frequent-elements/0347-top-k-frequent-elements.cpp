class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        unordered_map<int,int>freq;
        int n=nums.size();
        for(int i=0;i<n;i++){
              freq[nums[i]]++;
        }
        for(auto &it:freq){
            pq.push({it.second,it.first});
            if(pq.size()>k)
            pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};