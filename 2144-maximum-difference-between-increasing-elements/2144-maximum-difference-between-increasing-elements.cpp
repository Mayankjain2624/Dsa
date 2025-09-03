class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=0;
        int mini=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
             mini=min(mini,nums[i]);
             ans=max(ans,nums[i]-mini);
        }
        if(ans<=0)
        return -1;
        return ans;
    }
};