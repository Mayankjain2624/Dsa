class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int l=-1;
        for(int i=0;i<n;i++){
            if(nums[i]!=0)
            {
                nums[++l]=nums[i];
            }
        }
        for(int i=l+1;i<n;i++){
            nums[i]=0;
        }
    }
};