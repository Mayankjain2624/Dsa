class Solution {
public:
# define p pair<int,int>
    vector<int> findXSum(vector<int>& nums, int k, int x) {
       vector<int>ans;
        priority_queue<p,vector<p>,greater<p>>pq;
        for(int i=0;i<nums.size()-k+1;i++){
             map<int,int>mp;
            for(int j=i;j<i+k;j++){
                mp[nums[j]]++;
            }
             //min heap
            
            for(auto it:mp){
                pq.push({it.second,it.first});
                if(pq.size()>x){
                    pq.pop();
                }
            }
            int sum=0;
            while(!pq.empty()){
                p pp=pq.top();
                sum+= pp.first*pp.second;
                pq.pop();
            }
            ans.push_back(sum);

        }
        return ans;
    }
};