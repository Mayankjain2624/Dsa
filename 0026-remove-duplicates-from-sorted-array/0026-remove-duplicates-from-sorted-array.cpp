class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        vector<int>nc(n+1);
        nc[0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[l]==nums[i])
            continue;
            else
            {
                nums[l+1]=nums[i];
                l++;
            }
        }
        return l+1;
    }
};