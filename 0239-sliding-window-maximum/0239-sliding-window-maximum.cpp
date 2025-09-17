class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int>mp;
        int maxi=-1e9;
        int n=nums.size();
        for(int i=0;i<k;i++){
            maxi=max(maxi,nums[i]);
            mp[nums[i]]++;
        }
        vector<int>ans;
        ans.push_back(maxi);
        for(int j=k;j<n;j++){
            int l=j-k;
            mp[nums[l]]--;
            if(mp[nums[l]]==0)
            {
            mp.erase(nums[l]);
            }
            mp[nums[j]]++;
            maxi=(*mp.rbegin()).first;
            ans.push_back(maxi);
        }
        return ans;
    }
};