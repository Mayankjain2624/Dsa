class Solution {
public:
    int findMin(vector<int>& nums) {
          int l = 0;
        int r = nums.size() - 1;
        int n=nums.size();
        int ans=INT_MAX;
        while (l <= r) {
            int mid = (l + r) / 2;
            // cout<<mid<<endl;]
            ans=min(ans,nums[mid]);
            if(nums[mid]<nums[r]){
                r=mid-1; 
            }
            else
            {
               l=mid+1;
            }
        }
        return ans;
    }
};