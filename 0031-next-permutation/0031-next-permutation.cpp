class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        // int mini=n-1;
        for(int i=n-1;i>=1;i--){
            if(nums[i-1]<nums[i]){
              int minelement=nums[i],minelementindex=i;
              for(int j=i;j<n;j++){
                if(nums[j]>nums[i-1]){
                     if(nums[j]<minelement)
                     {
                        minelement=nums[j];
                        minelementindex=j;
                     }
                }
              }
              swap(nums[i-1],nums[minelementindex]);
            sort(nums.begin()+i,nums.end());
            return;
            }
        }
        sort(nums.begin(),nums.end());
        return;
    }
};