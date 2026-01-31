class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        // int mini=n-1;
        int k=0;
        for(int i=n-1;i>=1;i--){
            if(nums[i-1]<nums[i]){
              for(int j=n-1;j>=i;j--){
                    if(nums[j]>nums[i-1])
                    {
                    swap(nums[i-1],nums[j]);
                    break;
                    }
              }
            k=i;
            break;
            }
        }
       reverse(nums.begin() + k, nums.end());
        return;
    }
};