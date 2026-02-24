class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target)
            return mid;
            if(nums[mid]<target){
                ans=mid+1;
                l=mid+1;
            }
            else
            r=mid-1;
        }
        return l;
    }
};