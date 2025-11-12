class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int cnt0=0;
        int ans=0;
        for(int j=0;j<n;j++){
            if(nums[j]==0)
            cnt0++;
            while(cnt0>k)
            {
                if(nums[l]==0)
                cnt0--;
                l++;
            }
         ans=max(ans,j-l+1);
        }
        return  ans;
    }
};