class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int pr=1;
        int l=0;
        int r=0;
        int ans=0;
        int n=nums.size();
        while(r<n){
            pr*=nums[r];
            while(l<=r && pr>=k){
                pr/=nums[l];
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
};