class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int prevBest=0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(prevBest>=0)
            {
                prevBest+=nums[i];
            }
            else
            {
                prevBest=nums[i];
            }
                ans=max(ans,prevBest);
        }
        return ans;
    }
};